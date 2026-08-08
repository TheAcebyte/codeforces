#include <iostream>
#include <set>
#include <vector>

struct edge {
  int v, w;
};

using adjacency_list = std::vector<std::vector<edge>>;

void solve() {
  int n, a, b;
  std::cin >> n >> a >> b;
  --a; --b;

  adjacency_list edges(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    --u; --v;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }

  std::set<int> valid_x;
  auto target_dfs = [&](this auto&& self, int u, int p, int x) -> void {
    if (u != b) {
      valid_x.insert(x);
    }

    for (auto [v, w] : edges[u]) {
      if (v == p) continue;
      self(v, u, x ^ w);
    }
  };

  auto source_dfs = [&](this auto&& self, int u, int p, int x) -> bool {
    if (valid_x.find(x) != valid_x.end()) {
      return true;
    }

    for (auto [v, w] : edges[u]) {
      if (v == p || v == b) continue;
      if (self(v, u, x ^ w)) {
        return true;
      }
    }

    return false;
  };

  target_dfs(b, n, 0);
  bool ok = source_dfs(a, n, 0);
  std::cout << (ok ? "YES" : "NO") << '\n';
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
