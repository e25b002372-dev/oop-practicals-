#include <iomanip>
#include <iostream>
#include <string>

int main() {
    const double passMark = 40.0;
    std::string name;
    int test1, test2;

    std::cout << "Student name: ";
    std::getline(std::cin, name);
    std::cout << "Enter two test marks (0 to 100): ";
    if (!(std::cin >> test1 >> test2) || test1 < 0 || test1 > 100 ||
        test2 < 0 || test2 > 100) {
        std::cout << "Please enter two whole numbers from 0 to 100.\n";
        return 1;
    }

    double average = (test1 + test2) / 2.0;
    bool passed = test1 >= passMark && test2 >= passMark;
    std::cout << "Student: " << name << "\nMarks: " << test1 << ", " << test2
              << "\nAverage: " << std::fixed << std::setprecision(1) << average
              << "\nResult: " << (passed ? "Pass" : "Fail") << '\n';
}
