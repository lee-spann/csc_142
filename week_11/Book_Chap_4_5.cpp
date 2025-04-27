#include <iostream>
#include <chrono>

struct TimerClass {
    using clock = std::chrono::high_resolution_clock;
    using time_point = std::chrono::time_point<clock>;

    time_point* timestamp;
    const char* timerName; // <-- added to store timer name

    // Constructor
    TimerClass(const char* name) : timerName(name) {
        timestamp = new time_point(clock::now());
    }

    // Destructor
    ~TimerClass() {
        if (timestamp) {
            auto end_time = clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - *timestamp);
            std::cout << "Timer [" << timerName << "] lasted: " << duration.count() << " microseconds" << std::endl;
            delete timestamp;
        }
    }

    // Copy constructor
    TimerClass(const TimerClass& other) {
        timestamp = other.timestamp;
        timerName = other.timerName;
    }

    // Copy assignment
    TimerClass& operator=(const TimerClass& other) {
        if (this != &other) {
            timestamp = other.timestamp;
            timerName = other.timerName;
        }
        return *this;
    }

    // Move constructor
    TimerClass(TimerClass&& other) noexcept {
        timestamp = other.timestamp;
        timerName = other.timerName;
        other.timestamp = nullptr;
        other.timerName = nullptr;
    }

    // Move assignment
    TimerClass& operator=(TimerClass&& other) noexcept {
        if (this != &other) {
            delete timestamp; // free current resource
            timestamp = other.timestamp;
            timerName = other.timerName;
            other.timestamp = nullptr;
            other.timerName = nullptr;
        }
        return *this;
    }
};

int main() {
    TimerClass timer1("First Timer");
    TimerClass timer2 = std::move(timer1); // Uses move constructor

    // Do some work
    for (int i = 0; i < 1000000; ++i) {
        int x = i * i;
    }

    return 0;
}
