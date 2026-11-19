#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
struct Student { int id; std::string name; int marks; };
bool parse(const std::string& line, Student& s) {
    std::istringstream in(line); char sep;
    return (in >> s.id >> std::noskipws >> sep) && sep == ',' && std::getline(in,s.name,',') && !s.name.empty()
        && (in >> s.marks) && in.peek()==EOF && s.id>0 && s.marks>=0 && s.marks<=100;
}
int main() {
    std::ofstream out("students.csv");
    for (const auto& s : std::vector<Student>{{1,"Asha",81},{2,"Om",74},{3,"Sara",90}})
        out << s.id << ',' << s.name << ',' << s.marks << '\n';
    out.close(); if (!out) { std::cerr << "Cannot write students.csv\n"; return 1; }
    std::ifstream in("students.csv"); if (!in) { std::cerr << "Cannot read students.csv\n"; return 1; }
    std::string line;
    while (std::getline(in,line)) {
        Student s{};
        if (parse(line,s)) std::cout << s.id << ": " << s.name << " scored " << s.marks << '\n';
        else std::cerr << "Skipping malformed row: " << line << '\n';
    }
    std::fstream pos("positions.txt",std::ios::in|std::ios::out|std::ios::trunc|std::ios::binary);
    pos << "ABCDE"; std::cout << "tellp after writing: " << pos.tellp() << '\n';
    pos.seekp(2); pos.put('X'); pos.seekg(0); std::getline(pos,line);
    std::cout << "After seekp(2) and replacement: " << line << '\n';
    pos.clear(); pos.seekg(2); std::cout << "tellg after seekg(2): " << pos.tellg() << "; character: " << char(pos.get()) << '\n';
    if (!pos || in.bad()) { std::cerr << "File operation failed\n"; return 1; }
}
