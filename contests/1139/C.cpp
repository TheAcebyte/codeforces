#include <cassert>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

#define M 1000000007

using i64 = std::int64_t;

class dsu {
private:
  std::size_t n;
  std::vector<std::size_t> p;
  std::vector<std::size_t> sizes;

  std::size_t find(std::size_t u) {
    if (p[u] == u) {
      return u;
    }

    return p[u] = find(p[u]);
  }

public:
  dsu(std::size_t n) : n(n), p(n), sizes(n, 1) {
    std::iota(p.begin(), p.end(), 0);
  }

  std::size_t find_set(std::size_t u) {
    assert(u < n);
    return find(u);
  }

  void union_sets(std::size_t u, std::size_t v) {
    assert(u < n && v < n);
    std::size_t s = find_set(u);
    std::size_t t = find_set(v);
    if (s == t) {
      return;
    }

    if (sizes[s] < sizes[t]) {
      std::swap(s, t);
    }

    p[t] = s;
    sizes[s] += sizes[t];
  }

  std::size_t get_size(std::size_t u) {
    std::size_t s = find_set(u);
    return sizes[s];
  }
};

i64 power(i64 x, i64 n) {
  i64 result = 1;
  while (n > 0) {
    if (n & 1) {
      result = (result * x) % M;
    }

    x = (x * x) % M;
    n >>= 1;
  }

  return result;
}

i64 mod(i64 x) {
  i64 result = x % M;
  return result < 0 ? result + M : result;
}

void solve() {
  int n, k;
  std::cin >> n >> k;

  dsu sets(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, x;
    std::cin >> u >> v >> x;
    --u;
    --v;

    if (x == 0) {
      sets.union_sets(u, v);
    }
  }

  i64 result = power(n, k);
  for (int u = 0; u < n; ++u) {
    int p = sets.find_set(u);
    if (p == u) {
      int size = sets.get_size(p);
      result = mod(result - power(size, k));
    }
  }

  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
