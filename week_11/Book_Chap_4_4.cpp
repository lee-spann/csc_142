#include <iostream>
#include <chrono>

struct TimerClass {
    using clock = std::chrono::high_resolution_clock;
    using time_point = std::chrono::time_point<clock>;

    time_point* timestamp;

    // Constructor
    TimerClass() {
        timestamp = new time_point(clock::now());
    }

    // Destructor
    ~TimerClass() {
        if (timestamp) {
            auto end_time = clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - *timestamp);
            std::cout << "Timer lasted: " << duration.count() << " microseconds" << std::endl;
            delete timestamp;
        }
    }

    // Copy constructor
    TimerClass(const TimerClass& other) {
        timestamp = other.timestamp;
    }

    // Copy assignment
    TimerClass& operator=(const TimerClass& other) {
        if (this != &other) {
            timestamp = other.timestamp;
        }
        return *this;
    }

    // Move constructor
    TimerClass(TimerClass&& other) noexcept {
        timestamp = other.timestamp;
        other.timestamp = nullptr;
    }

    // Move assignment
    TimerClass& operator=(TimerClass&& other) noexcept {
        if (this != &other) {
            delete timestamp; // free current resource
            timestamp = other.timestamp;
            other.timestamp = nullptr;
        }
        return *this;
    }
};

int main() {
    TimerClass timer1;
    TimerClass timer2 = std::move(timer1); // Uses move constructor

    // Do some work
    for (int i = 0; i < 1000000; ++i) {
        int x = i * i;
    }

    return 0;
}
