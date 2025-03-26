#include "matrix.hpp" // helper
#include <iostream>
#include <stdexcept>
#include <algorithm> // for std::swap

// Function to initialize an empty NxN matrix with all values set to 0
Matrix::Matrix(std::size_t N) : matrix(N, std::vector<int>(N, 0)) {}

// Function to initialize the matrix with a given 2D vector of ints
Matrix::Matrix(std::vector<std::vector<int>> nums) : matrix(nums) {}

// Overloaded operator+ to add two matrices element-wise
Matrix Matrix::operator+(const Matrix &rhs) const {
    if (matrix.size() != rhs.matrix.size())
        throw std::invalid_argument("Matrices must be of the same size for addition.");

    std::size_t N = matrix.size();
    Matrix result(N);
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            result.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
        }
    }
    return result;
}

// Overloaded operator* to perform standard matrix multiplication
Matrix Matrix::operator*(const Matrix &rhs) const {
    if (matrix.size() != rhs.matrix.size())
        throw std::invalid_argument("Matrices must be of the same size for multiplication.");

    std::size_t N = matrix.size();
    Matrix result(N);
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            int sum = 0;
            for (std::size_t k = 0; k < N; ++k) {
                sum += matrix[i][k] * rhs.matrix[k][j];
            }
            result.matrix[i][j] = sum;
        }
    }
    return result;
}

// Set the value at row i and column j
void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    if (i >= matrix.size() || j >= matrix.size())
        throw std::out_of_range("Index out of bounds in set_value");
    matrix[i][j] = n;
}

// Get the value at row i and column j
int Matrix::get_value(std::size_t i, std::size_t j) const {
    if (i >= matrix.size() || j >= matrix.size())
        throw std::out_of_range("Index out of bounds in get_value");
    return matrix[i][j];
}

// Return the size of the matrix (NxN, so just N)
int Matrix::get_size() const {
    return matrix.size();
}

// Sum the major (primary) diagonal (top-left to bottom-right)
int Matrix::sum_diagonal_major() const {
    int sum = 0;
    std::size_t N = matrix.size();
    for (std::size_t i = 0; i < N; ++i) {
        sum += matrix[i][i];
    }
    return sum;
}

// Sum the minor diagonal (top-right to bottom-left)
int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    std::size_t N = matrix.size();
    for (std::size_t i = 0; i < N; ++i) {
        sum += matrix[i][N - 1 - i];
    }
    return sum;
}

// Swap two rows, r1 and r2, in the matrix
void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    if (r1 >= matrix.size() || r2 >= matrix.size())
        throw std::out_of_range("Row index out of bounds in swap_rows");
    std::swap(matrix[r1], matrix[r2]);
}

// Swap two columns, c1 and c2, in the matrix
void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    std::size_t N = matrix.size();
    if (c1 >= N || c2 >= N)
        throw std::out_of_range("Column index out of bounds in swap_cols");
    for (std::size_t i = 0; i < N; ++i) {
        std::swap(matrix[i][c1], matrix[i][c2]);
    }
}

// Print the matrix to standard output
void Matrix::print_matrix() const {
    std::size_t N = matrix.size();
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}