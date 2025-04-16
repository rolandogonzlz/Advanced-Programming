#include <iostream>
#include <algorithm>
#include <chrono>

class Buffer {
private:
    int* data;
    size_t size;

public:
    Buffer(size_t s) : size(s), data(new int[s]) {
        std::fill(data, data + size, 42); // Fill with dummy data
        std::cout << "Constructor called\n";
    }

    ~Buffer() {
        delete[] data;
        std::cout << "Destructor called\n";
    }

    Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) {
        std::copy(other.data, other.data + other.size, data);
        std::cout << "Copy constructor called\n";
    }

    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            std::copy(other.data, other.data + size, data);
            std::cout << "Copy assignment called\n";
        }
        return *this;
    }

    Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move constructor called\n";
    }

    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
            std::cout << "Move assignment called\n";
        }
        return *this;
    }
};

int main() {
    const size_t largeSize = 10'000'000;

    std::cout << "=== Copy Constructor Timing ===\n";
    Buffer original(largeSize);

    auto start_copy = std::chrono::high_resolution_clock::now();
    Buffer copy = original; // Calls copy constructor
    auto end_copy = std::chrono::high_resolution_clock::now();
    std::cout << "Copy duration: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end_copy - start_copy).count()
              << " ms\n";

    std::cout << "\n=== Move Constructor Timing ===\n";
    auto start_move = std::chrono::high_resolution_clock::now();
    Buffer moved = std::move(copy); // Calls move constructor
    auto end_move = std::chrono::high_resolution_clock::now();
    std::cout << "Move duration: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end_move - start_move).count()
              << " ms\n";

    return 0;
}

