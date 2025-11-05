#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T> class Matrix {
private:
  std::size_t n;
  std::vector<T> data;

public:
  Matrix(std::size_t n, T initializer)
      : n(n), data(std::vector<T>(n * n, initializer)) {}
  Matrix(std::size_t n) : n(n), data(std::vector<T>(n * n)) {}

  Matrix(const Matrix &other) = default;
  Matrix &operator=(const Matrix &other) = default;

  Matrix(Matrix &&other) noexcept = default;
  Matrix &operator=(Matrix &&other) noexcept = default;

  static Matrix identity(std::size_t n) {
    Matrix matrix(n, T(0));
    for (std::size_t i = 0; i < n; ++i) {
      matrix[i][i] = T(1);
    }

    return matrix;
  }

  std::size_t size() const { return n; }

  T &at(std::size_t row, std::size_t col) {
    if (row >= n || col >= n) {
      throw std::out_of_range("Matrix index is out of range");
    }

    return data[row * n + col];
  }

  const T &at(std::size_t row, std::size_t col) const {
    if (row >= n || col >= n) {
      throw std::out_of_range("Matrix index is out of range");
    }

    return data[row * n + col];
  }

  typename std::vector<T>::iterator operator[](std::size_t row) {
    return data.begin() + n * row;
  }

  typename std::vector<T>::const_iterator operator[](std::size_t row) const {
    return data.begin() + n * row;
  }

  Matrix &operator*=(Matrix other) {
    if (n != other.n) {
      throw std::runtime_error(
          "Cannot multiply two matrices with different sizes.");
    }

    Matrix result(n, T(0));
    for (std::size_t i = 0; i < n; ++i) {
      for (std::size_t j = 0; j < n; ++j) {
        for (std::size_t k = 0; k < n; ++k) {
          result[i][j] += (*this)[i][k] * other[k][j];
        }
      }
    }

    *this = std::move(result);
    return *this;
  }

  Matrix &operator^=(unsigned long long exp) {
    Matrix result = Matrix::identity(n);
    Matrix base(*this);

    while (exp != 0) {
      if (exp & 1) {
        result *= base;
      }
      base *= base;
      exp >>= 1;
    }

    *this = std::move(result);
    return *this;
  }

  std::vector<T> operator*(const std::vector<T> &vector) {
    if (vector.size() != n) {
      throw std::runtime_error(
          "Cannot multiply matrix and vector with different dimensions");
    }

    std::vector<T> result(n, T(0));
    for (std::size_t i = 0; i < n; ++i) {
      for (std::size_t j = 0; j < n; ++j) {
        result[i] += (*this)[i][j] * vector[j];
      }
    }

    return result;
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Matrix<T> &matrix) {
  for (std::size_t i = 0; i < matrix.size(); ++i) {
    out << '[';
    const char *separator = "";
    for (std::size_t j = 0; j < matrix.size(); ++j) {
      out << separator << matrix[i][j];
      separator = ", ";
    }
    out << "]\n";
  }

  return out;
}
