#include <iostream>
#include <chrono>

struct TimerClass {
    using clock = std::chrono::high_resolution_clock;
    using time_point = std::chrono::time_point<clock>;

    time_point timestamp;

    TimerClass() {
        timestamp = clock::now();  // Save start time
    }

    ~TimerClass() {
        auto end_time = clock::now();  // Get end time
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - timestamp);
        std::cout << "Timer lasted: " << duration.count() << " microseconds" << std::endl;
    }
};

int main() {
    TimerClass timer;

    // Do something that takes time
    for (int i = 0; i < 1000000; ++i) {
        int x = i * i;
    }

    return 0;
}




