#include <cmath>
#include <random>

class Annealer {
    double temp_start;
    double temp_end;
    double time_limit;

    std::mt19937 engine;
    std::uniform_real_distribution<> dist;

    double current_temp(double time) {
        if (time_limit < time) time = time_limit;
        return temp_start + (temp_end - temp_start) * time / time_limit;
    }

public:
    Annealer(double temp_start, double temp_end, double time_limit) :
        temp_start(temp_start), temp_end(temp_end),
        time_limit(time_limit),
        engine(std::random_device()()), dist(0.0, 1.0) {}
    
    bool modify(double diff, double time) {
        double temp = this->current_temp(time);
        double prob = std::exp(diff / temp);
        return this->dist(engine) < prob;
    }
};