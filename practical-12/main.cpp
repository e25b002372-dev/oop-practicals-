#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
using std::string;
struct LibraryError : std::runtime_error { using runtime_error::runtime_error; };
class CatalogItem {
    string id_, title_;
public:
    CatalogItem(string id,string title) : id_(id), title_(title) {}
    const string& id() const { return id_; }
    const string& title() const { return title_; }
};
class Book : public CatalogItem {
    string author_; bool available_;
public:
    Book(string id,string title,string author,bool available=true)
        : CatalogItem(id,title), author_(author), available_(available) {}
    bool available() const { return available_; }
    void setAvailable(bool next) {
        if (next==available_) throw LibraryError(next ? "Already available" : "Already issued");
        available_=next;
    }
    const string& author() const { return author_; }
    void display() const { std::cout << id() << " | " << title() << " | " << author_ << " | " << (available_?"available":"issued") << '\n'; }
};
class Library {
    std::map<string,Book> books;
    const string path="library.tsv";
    static bool valid(const string& field) {
        return field.find_first_not_of(' ')!=string::npos && field.find_first_of("\t\r\n")==string::npos;
    }
    void insert(const Book& b) {
        if (!valid(b.id()) || !valid(b.title()) || !valid(b.author())) throw LibraryError("Enter nonblank fields without tabs");
        if (!books.emplace(b.id(),b).second) throw LibraryError("Duplicate ID");
    }
    void save() const {
        string tmp=path+".tmp"; std::ofstream out(tmp);
        for (const auto& entry:books) {
            const auto& b=entry.second;
            out << b.id() << '\t' << b.title() << '\t' << b.author() << '\t' << b.available() << '\n';
        }
        out.close();
        if (!out || std::rename(tmp.c_str(),path.c_str())!=0) throw LibraryError("Save failed; previous file retained");
    }
public:
    Library() {
        if (!std::filesystem::exists(path)) return;
        std::ifstream in(path); if (!in) throw LibraryError("Cannot open catalog");
        string row; int n=0;
        while (std::getline(in,row)) {
            ++n; auto a=row.find('\t'), b=a==string::npos?a:row.find('\t',a+1), c=b==string::npos?b:row.find('\t',b+1);
            if (c==string::npos || (row.substr(c+1)!="1" && row.substr(c+1)!="0")) throw LibraryError("Malformed catalog row " + std::to_string(n));
            insert(Book(row.substr(0,a),row.substr(a+1,b-a-1),row.substr(b+1,c-b-1),row.back()=='1'));
        }
        if (in.bad()) throw LibraryError("Catalog read failed");
    }
    void add(const Book& b) { insert(b); try { save(); } catch (...) { books.erase(b.id()); throw; } }
    Book& find(const string& id) {
        auto it=books.find(id); if (it==books.end()) throw LibraryError("Unknown ID"); return it->second;
    }
    void change(const string& id,bool next) {
        auto& b=find(id); b.setAvailable(next); try { save(); } catch (...) { b.setAvailable(!next); throw; }
    }
    void list() const {
        if (books.empty()) std::cout << "Catalog is empty\n";
        for (const auto& entry:books) entry.second.display();
    }
};
string ask(const char* prompt) {
    std::cout << prompt; string value;
    if (!std::getline(std::cin,value)) throw std::ios_base::failure("Input ended");
    return value;
}
int main() {
    try {
        Library lib; std::cout << "Commands: add, search, list, issue, return, quit\n";
        string cmd;
        while (std::cout << "> " && std::getline(std::cin,cmd) && cmd!="quit") {
            try {
                if (cmd=="list") lib.list();
                else if (cmd=="add") {
                    auto id=ask("ID: "); auto title=ask("Title: "); auto author=ask("Author: ");
                    lib.add(Book(id,title,author)); std::cout << "Added\n";
                } else if (cmd=="search") lib.find(ask("ID: ")).display();
                else if (cmd=="issue" || cmd=="return") { lib.change(ask("ID: "),cmd=="return"); std::cout << "Updated\n"; }
                else std::cout << "Unknown command\n";
            } catch (const LibraryError& e) { std::cout << "Error: " << e.what() << '\n'; }
        }
    } catch (const std::exception& e) { std::cerr << "Stopped: " << e.what() << '\n'; return 1; }
}
