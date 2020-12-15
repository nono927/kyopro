#include <vector>
#include <utility>

template<typename T>
class Matrix {
    std::vector<std::vector<T> > data_;

public:
    // constructor
    Matrix(int size) {
        this->data_ = std::vector<std::vector<T> >(size, std::vector<T>(size));
    }

    Matrix(int rows, int cols) {
        this->data_ = std::vector<std::vector<T> >(rows, std::vector<T>(cols));
    }

    Matrix(std::initializer_list<std::initializer_list<T> > init)
        : data_(init.begin(), init.end()) {
    }

    Matrix(const Matrix<T> &m) {
        this->data_ = m.data_;
    }

    Matrix(Matrix<T> &&m) noexcept {
        this->data_ = std::move(m.data_);
    }

    // size
    int rows() const {
        return this->data_.size();
    }

    int cols() const {
        if (data_.empty()) return 0;
        return  this->data_[0].size();
    }

    // overload
    Matrix<T> &operator=(const Matrix<T> &m) {
        this->data_ = m.data_;
        return *this;
    }

    Matrix<T> &operator=(const Matrix<T> &&m) {
        this->data_ = std::move(m.data_);
        return *this;
    }

    const std::vector<T> &operator[](int i) const {
        return this->data_[i];
    }

    std::vector<T> &operator[](int i) {
        return this->data_[i];
    }

    Matrix<T> operator-() const {
        Matrix<T> m(this->cols, this->rows);
        for (auto &vec : data_) {
            for (auto &e : vec) {
                e = -e;
            }
        }
        return m;
    }

    Matrix<T> &operator+=(const Matrix<T> &m) {
        for (int i = 0; i < this->rows(); ++i) {
            for (int j = 0; j < this->cols(); ++j) {
                this->data_[i][j] += m[i][j];
            }
        }
        return *this;
    }

    Matrix<T> &operator-=(const Matrix<T> &m) {
        for (int i = 0; i < this->rows(); ++i) {
            for (int j = 0; j < this->cols(); ++j) {
                this->data_[i][j] -= m[i][j];
            }
        }
        return *this;
    }

    // utilities
    Matrix<T> pow(int n) {
        Matrix<T> ret = Matrix<T>::ones(this->rows());
        Matrix<T> m = *this;
        while (n > 0) {
            if (n & 1) ret = ret * m;
            m = m * m;
            n >>= 1;
        }
        return ret;
    }

    Matrix<T> transpose() const {
        Matrix<T> ret(this->cols(), this->rows());
        for (int i = 0; i < this->cols(); ++i) {
            for (int j = 0; j < this->rows(); ++j) {
                ret[i][j] = (*this)[j][i];
            }
        }
        return ret;
    }

    // static method
    static Matrix<T> ones(const int size) {
        Matrix<T> ret(size, size);
        for (int i = 0; i < size; ++i) {
            ret[i][i] = 1;
        }
        return ret;
    }
};

template<typename T>
Matrix<T> operator+(const Matrix<T> &m1, const Matrix<T> &m2) {
    return Matrix<T>(m1) += m2;
}

template<typename T>
Matrix<T> operator-(const Matrix<T> &m1, const Matrix<T> &m2) {
    return Matrix<T>(m1) -= m2;
}

template<typename T>
Matrix<T> operator*(const Matrix<T> &m1, const Matrix<T> &m2) {
    Matrix<T> mat(m1.rows(), m2.cols());
    for (int i = 0; i < mat.rows(); ++i) {
        for (int j = 0; j < mat.cols(); ++j) {
            mat[i][j] = 0;
            for (int k = 0; k < m1.cols(); ++k) {
                mat[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return mat;
}

