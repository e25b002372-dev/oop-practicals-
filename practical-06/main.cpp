#include <iostream>
#include <iomanip>
class Shape { public: virtual double area() const = 0; virtual ~Shape() = default; };
class Circle : public Shape {
    double r;
public: explicit Circle(double radius) : r(radius) {}
    double area() const override { return 3.141592653589793*r*r; }
};
class Rectangle : public Shape {
    double w,h;
public: Rectangle(double width,double height) : w(width), h(height) {}
    double area() const override { return w*h; }
};
class Triangle : public Shape {
    double b,h;
public: Triangle(double base,double height) : b(base), h(height) {}
    double area() const override { return b*h/2; }
};
void report(const char* label,const Shape& shape) { std::cout << label << ": " << shape.area() << '\n'; }
int main() {
    std::cout << std::fixed << std::setprecision(2);
    report("Circle",Circle(3)); report("Rectangle",Rectangle(4,5)); report("Triangle",Triangle(6,3));
}
