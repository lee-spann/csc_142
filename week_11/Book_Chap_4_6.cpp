#include <iostream>
#include <chrono>
#include <cmath>


struct TimerClass {
    using clock = std::chrono::high_resolution_clock;
    using time_point = std::chrono::time_point<clock>;

    time_point* timestamp;
    const char* timerName;

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
            delete timestamp; 
            timestamp = other.timestamp;
            timerName = other.timerName;
            other.timestamp = nullptr;
            other.timerName = nullptr;
        }
        return *this;
    }
};

// A function that takes a TimerClass by move
void heavyComputation(TimerClass timer) {
    // Big math loop
    volatile double result = 0.0;
    for (int i = 0; i < 10000000; ++i) {
        result += std::sin(i) * std::cos(i);
    }
    // Timer will be destroyed automatically when function ends
}

int main() {
    TimerClass timer("Heavy Computation Timer");

    // Move the timer into the function
    heavyComputation(std::move(timer));

    return 0;
}
