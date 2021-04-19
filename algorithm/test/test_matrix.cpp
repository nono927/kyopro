#include "gtest/gtest.h"
#include "matrix.hpp"

TEST(Matrix, Assign) {
    Matrix<int> mat(2, 2);
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[1][0] = 3;
    mat[1][1] = 4;

    ASSERT_EQ(mat[0][0], 1);
    ASSERT_EQ(mat[0][1], 2);
    ASSERT_EQ(mat[1][0], 3);
    ASSERT_EQ(mat[1][1], 4);
}

TEST(Matrix, Initialize) {
    Matrix<int> mat({
            {1, 2},
            {3, 4}
        });

    ASSERT_EQ(mat[0][0], 1);
    ASSERT_EQ(mat[0][1], 2);
    ASSERT_EQ(mat[1][0], 3);
    ASSERT_EQ(mat[1][1], 4);
}

TEST(Matrix, Copy) {
    Matrix<int> m1({
            {1, 2},
            {3, 4}
        });
    Matrix<int> m2(m1);

    ASSERT_EQ(m2[0][0], 1);
    ASSERT_EQ(m2[0][1], 2);
    ASSERT_EQ(m2[1][0], 3);
    ASSERT_EQ(m2[1][1], 4);
}

TEST(Matrix, Add) {
    Matrix<int> m1({
            {1, 2},
            {3, 4}
        });
    Matrix<int> m2({
            {5, 6},
            {7, 8}
        });

    auto mat = m1 + m2;

    ASSERT_EQ(mat[0][0], 6);
    ASSERT_EQ(mat[0][1], 8);
    ASSERT_EQ(mat[1][0], 10);
    ASSERT_EQ(mat[1][1], 12);
}

TEST(Matrix, Sub) {
    Matrix<int> m1({
            {1, 2},
            {3, 4}
        });
    Matrix<int> m2({
            {5, 6},
            {7, 8}
        });

    auto mat = m2 - m1;

    ASSERT_EQ(mat[0][0], 4);
    ASSERT_EQ(mat[0][1], 4);
    ASSERT_EQ(mat[1][0], 4);
    ASSERT_EQ(mat[1][1], 4);
}

TEST(Matrix, Mul) {
    Matrix<int> m1({
            {1, 2},
            {3, 4}
        });
    Matrix<int> m2({
            {5, 6},
            {7, 8}
        });

    auto mat = m1 * m2;

    ASSERT_EQ(mat[0][0], 19);
    ASSERT_EQ(mat[0][1], 22);
    ASSERT_EQ(mat[1][0], 43);
    ASSERT_EQ(mat[1][1], 50);
}

TEST(Matrix, Pow) {
    Matrix<int> m1({
            {1, 2},
            {3, 4}
        });

    auto mat = m1.pow(10);

    ASSERT_EQ(mat[0][0], 4783807);
    ASSERT_EQ(mat[0][1], 6972050);
    ASSERT_EQ(mat[1][0], 10458075);
    ASSERT_EQ(mat[1][1], 15241882);
}

TEST(Matrix, Transpose) {
    Matrix<int> m1({
            {1, 2},
            {3, 4}
        });

    auto mat = m1.transpose();

    ASSERT_EQ(mat[0][0], 1);
    ASSERT_EQ(mat[0][1], 3);
    ASSERT_EQ(mat[1][0], 2);
    ASSERT_EQ(mat[1][1], 4);
}

