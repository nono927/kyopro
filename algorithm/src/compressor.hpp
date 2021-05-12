#include <vector>
#include <algorithm>

template <class T>
class Compressor {
    std::vector<T> vals;

public:
    Compressor(std::vector<T> &v){
        vals.resize(v.size());
        std::copy(v.begin(), v.end(), vals.begin());
        std::sort(vals.begin(), vals.end());
        vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
    }

    std::vector<size_t> compress(std::vector<T> &v) {
        std::vector<size_t> ret(v.size());
        for (size_t i = 0; i < v.size(); ++i) {
            ret[i] = std::distance(
                        vals.begin(),
                        std::lower_bound(vals.begin(), vals.end(), v[i])
                    );
        }
        return ret;
    }

    T operator[](size_t i) {
        return vals[i];
    }
};