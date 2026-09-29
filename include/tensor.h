#pragma once

#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

template <int N> using size_array = std::array<int, N>;

template <typename T, int N> class tensor_view {
  static_assert(N > 0);

private:
  template <typename S, int M> friend class tensor;
  template <typename S, int M> friend class tensor_view;

  const int *shape;
  const int *strides;
  T *data;

  tensor_view(const int *shape, const int *strides, T *data)
      : shape(shape), strides(strides), data(data) {}

  int flatten_indices(const size_array<N> &indices) const {
    int j = 0;
    for (int i = 0; i < N; ++i) {
      j += indices[i] * strides[i];
    }

    return j;
  }

  int flatten_indices_checked(const size_array<N> &indices) const {
    int j = 0;
    for (int i = 0; i < N; ++i) {
      assert(indices[i] >= 0 && indices[i] < shape[i]);
      j += indices[i] * strides[i];
    }

    return j;
  }

public:
  T &operator[](const size_array<N> &indices) const {
    int i = flatten_indices(indices);
    return data[i];
  }

  T &at(const size_array<N> &indices) const {
    int i = flatten_indices_checked(indices);
    return data[i];
  }

  decltype(auto) operator[](int i) const {
    if constexpr (N == 1) {
      return data[i];
    } else {
      return tensor_view<T, N - 1>(shape + 1, strides + 1,
                                   data + i * strides[0]);
    }
  }

  decltype(auto) at(int i) const {
    assert(i >= 0 && i < shape[0]);
    return operator[](i);
  }
};

template <typename T, int N> class tensor {
  static_assert(N > 0);

private:
  size_array<N> shape;
  size_array<N> strides;
  std::vector<T> data;

  tensor_view<T, N> get_view() {
    return tensor_view<T, N>(shape.data(), strides.data(), data.data());
  }

  tensor_view<const T, N> get_view() const {
    return tensor_view<const T, N>(shape.data(), strides.data(), data.data());
  }

public:
  tensor(size_array<N> shape, const T &initial_value = T()) : shape(shape) {
    int size = 1;
    for (int i = N - 1; i >= 0; --i) {
      strides[i] = size;
      size *= shape[i];
    }

    data = std::vector<T>(size, initial_value);
  }

  template <typename I = size_array<N>> decltype(auto) operator[](I index) {
    return get_view()[index];
  }

  template <typename I = size_array<N>>
  decltype(auto) operator[](I index) const {
    return get_view()[index];
  }

  template <typename I = size_array<N>> decltype(auto) at(I index) {
    return get_view().at(index);
  }

  template <typename I = size_array<N>> decltype(auto) at(I index) const {
    return get_view().at(index);
  }
};
