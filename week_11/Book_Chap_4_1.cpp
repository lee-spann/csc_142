#include <chrono>
#include <iostream>

struct TimerClass {
  std::chrono::time_point<std::chrono::high_resolution_clock> timestamp;

  TimerClass() {
    timestamp = std::chrono::high_resolution_clock::now();
  }
};
