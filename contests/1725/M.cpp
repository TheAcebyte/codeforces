#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using u8 = std::uint8_t;
using i64 = std::int64_t;
constexpr i64 inf = 1e18;

template<typename T> void setmin(T& x, const T& y) { if (y < x) x = y; }

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

struct traversal {
  int u;
  i64 c;
  bool k;

  bool operator>(const traversal &other) const { return c > other.c; }
};

struct edge {
  int v;
  i64 w;
};

using adjacency_list = std::vector<std::vector<edge>>;

void solve() {
  int n, m;
  std::cin >> n >> m;

  adjacency_list incoming(n), outgoing(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    i64 w;
    std::cin >> u >> v >> w;
    --u; --v;
    outgoing[u].push_back({v, w});
    incoming[v].push_back({u, w});
  }

  tensor<u8, 2> visited({n, 2}, false);
  std::vector<i64> min_cost(n, inf);
  traversal root{0, 0, false};
  std::priority_queue<traversal, std::vector<traversal>,
                      std::greater<traversal>>
      queue;
  queue.push(root);
  while (!queue.empty()) {
    auto [u, c, k] = queue.top();
    queue.pop();

    if (visited[u][k]) continue;
    visited[u][k] = true;
    setmin(min_cost[u], c);

    for (auto [v, w] : incoming[u]) {
      queue.push({v, c + w, true});
    }

    if (k) continue;
    for (auto [v, w] : outgoing[u]) {
      queue.push({v, c + w, false});
    }
  }

  for (int u = 1; u < n; ++u) {
    i64 c = min_cost[u] == inf ? -1 : min_cost[u];
    std::cout << c << " \n"[u == n - 1];
  }
}

int main() {
#ifndef ONLINE_JUDGE
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
