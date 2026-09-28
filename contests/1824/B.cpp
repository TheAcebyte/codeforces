#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;
using adjacency_list = std::vector<std::vector<i64>>;

constexpr i64 M = 1e9 + 7;

i64 power_mod(i64 x, i64 n) {
  i64 y = 1;
  while (n > 0) {
    if (n & 1) y = (y * x) % M;
    x = (x * x) % M;
    n >>= 1;
  }

  return y;
}

i64 inverse_mod(i64 x) {
  return power_mod(x, M - 2);
}

void solve() {
  i64 n, k;
  std::cin >> n >> k;

  adjacency_list edges(n);
  for (i64 i = 0; i < n - 1; ++i) {
    i64 u, v;
    std::cin >> u >> v;
    --u; --v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  if (k == 1 || k == 3) {
    std::cout << 1 << '\n';
    return;
  }

  i64 good_islands = 0;
  auto calculate_good_islands = [&](this auto&& self, i64 u = 0, i64 p = -1) -> i64 {
    i64 d = 0;
    i64 s = 0;
    for (i64 v : edges[u]) {
      if (v == p) continue;
      i64 x = self(v, u);
      s = (s + x * d) % M;
      d += x;
    }

    i64 sum = n - 1;
    i64 sum_of_pairwise_products = (s + (n - d - 1) * d) % M;
    good_islands = (good_islands + sum + sum_of_pairwise_products) % M;
    return d + 1;
  };

  calculate_good_islands();
  i64 combinations = (n * (n - 1) / 2) % M;
  i64 expectation = (good_islands * inverse_mod(combinations)) % M;
  std::cout << expectation << '\n';
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
