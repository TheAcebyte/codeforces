#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>

using i64 = std::int64_t;
using adjacency_list = std::vector<std::vector<int>>;

struct interval {
  i64 l, r;
};

struct state {
  int u, k;

  bool operator<(const state& other) const {
    if (u < other.u) return true;
    if (u > other.u) return false;
    return k < other.k;
  }
};

void solve() {
  int n;
  std::cin >> n;

  std::vector<interval> a(n);
  for (auto& u : a) std::cin >> u.l >> u.r;

  adjacency_list edges(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u; --v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  std::map<state, i64> dp;
  auto dfs = [&](this auto&& self, int u, int k, int p = -1) -> i64 {
    state s = {u, k};
    if (dp.find(s) != dp.end()) {
      return dp[s];
    }

    i64 x = k == 0 ? a[u].l : a[u].r;
    i64 result = 0;
    for (int v : edges[u]) {
      if (v == p) continue;
      auto [l, r] = a[v];
      result += std::max(
          std::abs(x - l) + self(v, 0, u),
          std::abs(x - r) + self(v, 1, u)
          );
    }

    dp[s] = result;
    return result;
  };

  i64 result = std::max(dfs(0, 0), dfs(0, 1));
  std::cout << result << '\n';
}

int main() {
#ifndef ONLINE_JUDGE 
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t-- > 0) {
    solve();
  }

  return 0;
}
