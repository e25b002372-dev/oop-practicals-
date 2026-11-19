#include <algorithm>
#include <cstddef>
#include <iostream>
#include <utility>
class Buffer {
    std::size_t n{};
    int* data{};
public:
    Buffer() = default;
    explicit Buffer(std::size_t size) : n(size), data(new int[size]{}) {}
    ~Buffer() { delete[] data; } // Release owned storage.
    Buffer(const Buffer& other) : Buffer(other.n) { // Independent storage.
        if (n) std::copy_n(other.data, n, data);
    }
    Buffer& operator=(const Buffer& other) { // Copy first for exception safety.
        if (this != &other) { Buffer copy(other); *this = std::move(copy); }
        return *this;
    }
    Buffer(Buffer&& other) noexcept : n(std::exchange(other.n, 0)),
        data(std::exchange(other.data, nullptr)) {} // Take ownership.
    Buffer& operator=(Buffer&& other) noexcept { // Release then take ownership.
        if (this != &other) {
            delete[] data;
            data = std::exchange(other.data, nullptr);
            n = std::exchange(other.n, 0);
        }
        return *this;
    }
    std::size_t size() const { return n; }
    int& operator[](std::size_t i) { return data[i]; } // Requires i < size().
};
int main() {
    Buffer a(2); a[0] = 7;
    Buffer b(a), c; c = a; a[0] = 9;
    std::cout << "Original and independent copies: " << a[0] << ' ' << b[0] << ' ' << c[0] << '\n';
    Buffer d(std::move(b)), e; e = std::move(c);
    std::cout << "Moved values: " << d[0] << ' ' << e[0] << "\nSource sizes: " << b.size() << ' ' << c.size() << '\n';
}
