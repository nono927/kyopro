#include <vector>

template <class T>
class Compressor {
public:
    Compressor(std::vector<T> &v){}

    std::vector<size_t> compress(std::vector<T> &v) {
        return std::vector<size_t>();
    }

    T operator[](size_t i) {
        return T();
    }
};