#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <utility>

struct SimpleString {
    size_t max_size;
    size_t length;
    char* buffer;

    // Constructor
    SimpleString(size_t max_size_)
        : max_size(max_size_), length(0), buffer(nullptr) {
        if (max_size == 0) {
            throw std::runtime_error("Max size must be at least 1.");
        }
        buffer = new char[max_size];
        buffer[0] = '\0';
    }

    // Destructor
    ~SimpleString() {
        delete[] buffer;
    }

    // Copy constructor
    SimpleString(const SimpleString& other)
        : max_size(other.max_size), length(other.length) {
        buffer = new char[max_size];
        std::strncpy(buffer, other.buffer, max_size);
    }

    // Move constructor
    SimpleString(SimpleString&& other) noexcept
        : max_size(other.max_size), length(other.length), buffer(other.buffer) {
        other.buffer = nullptr;
        other.length = 0;
        other.max_size = 0;
    }

    // Copy assignment
    SimpleString& operator=(const SimpleString& other) {
        if (this != &other) {
            delete[] buffer;
            max_size = other.max_size;
            length = other.length;
            buffer = new char[max_size];
            std::strncpy(buffer, other.buffer, max_size);
        }
        return *this;
    }

    // Move assignment
    SimpleString& operator=(SimpleString&& other) noexcept {
        if (this != &other) {
            delete[] buffer;
            buffer = other.buffer;
            max_size = other.max_size;
            length = other.length;

            other.buffer = nullptr;
            other.max_size = 0;
            other.length = 0;
        }
        return *this;
    }

    // Print
    void print(const char* tag) const {
        printf("%s: %s", tag, buffer);
    }

    // Append line
    bool append_line(const char* x) {
        size_t x_len = std::strlen(x);
        if (length + x_len + 2 > max_size) { // +2 for '\n' and '\0'
            return false;
        }
        std::strncpy(buffer + length, x, max_size - length);
        length += x_len;
        buffer[length++] = '\n';
        buffer[length] = '\0';
        return true;
    }
};
