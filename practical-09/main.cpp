#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
template<class T> class Stack {
    std::vector<T> items;
public:
    bool empty() const { return items.empty(); }
    void push(const T& value) { items.push_back(value); }
    T top() const { if (empty()) throw std::underflow_error("Stack is empty"); return items.back(); }
    T pop() { T value = top(); items.pop_back(); return value; }
};
template<class T> void demo(T first,T second) {
    Stack<T> s; s.push(first); s.push(second);
    std::cout << "Top: " << s.top() << "; pop order: " << s.pop() << ", " << s.pop() << '\n';
    try { s.pop(); } catch (const std::underflow_error& e) { std::cout << e.what() << '\n'; }
}
int main() { demo(1,2); demo(1.5f,2.5f); demo<std::string>("first","second"); }
