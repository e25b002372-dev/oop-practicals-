#include <iostream>
int add(int a,int b) { return a+b; }
double add(double a,double b) { return a+b; }
struct Complex {
    double real, imag;
    Complex operator+(const Complex& rhs) const { return {real+rhs.real, imag+rhs.imag}; }
};
std::ostream& operator<<(std::ostream& out, Complex z) {
    return out << '(' << z.real << (z.imag>=0 ? "+" : "") << z.imag << "i)";
}
int main() {
    std::cout << "2 + 3 = " << add(2,3) << "\n2.5 + 3.25 = " << add(2.5,3.25) << '\n';
    Complex a{2,3}, b{4,-3}; std::cout << a << " + " << b << " = " << a+b << '\n';
}
