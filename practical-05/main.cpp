#include <iostream>
#include <string>
class Person {
    std::string name; int age;
public:
    Person(std::string n, int a) : name(n), age(a) {}
    void display() const { std::cout << name << ", age " << age; }
};
class Student : public Person {
    int id; std::string course;
public:
    Student(std::string n, int a, int i, std::string c) : Person(n,a), id(i), course(c) {}
    void display() const { Person::display(); std::cout << ", ID " << id << ", " << course; }
};
class GraduateStudent : public Student {
    std::string topic;
public:
    GraduateStudent(std::string n,int a,int i,std::string c,std::string t) : Student(n,a,i,c), topic(t) {}
    void display() const { Student::display(); std::cout << ", research: " << topic; }
};
int main() {
    Student s("Asha",19,101,"BSc"); GraduateStudent g("Kabir",23,202,"MSc","Databases");
    s.display(); std::cout << '\n'; g.display(); std::cout << '\n';
}
