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

    // Copy Constructor (shares timestamp)
    TimerClass(const TimerClass& other) {
        timestamp = other.timestamp;
    }

    // Copy Assignment Operator (shares timestamp)
    TimerClass& operator=(const TimerClass& other) {
        if (this != &other) {
            timestamp = other.timestamp;
        }
        return *this;
    }
};

int main() {
    TimerClass timer1;
    TimerClass timer2 = timer1; // Uses copy constructor

    // Do some work
    for (int i = 0; i < 1000000; ++i) {
        int x = i * i;
    }

    return 0;
}
