#include <chrono>

class Timer {
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point prev;

public:
    Timer() : start(std::chrono::system_clock::now()), prev(start) {}

    double time() {
        auto now = std::chrono::system_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
    }

    double lap() {
        auto now = std::chrono::system_clock::now();
        double ret = std::chrono::duration_cast<std::chrono::milliseconds>(now - prev).count();
        this->prev = now;
        return ret;
    }
};
