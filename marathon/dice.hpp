#include <random>

class Dice {
    std::mt19937 engine;
    std::uniform_int_distribution<> dist;
public:
    Dice(int n)
        : engine(std::random_device()()), dist(0, n-1) {}

    Dice(int n, int seed)
        : engine(seed), dist(0, n-1) {}

    int operator()() {
        return this->dist(this->engine);
    }
};
