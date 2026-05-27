#include <iostream>
#include <vector>

using adjacency_list = std::vector<std::vector<int>>;

void solve() {
  int n;
  std::cin >> n;

  bool identical_pair = false;
  adjacency_list edges(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    edges[a].push_back(b);
    edges[b].push_back(a);

    if (a == b) {
      identical_pair = true;
    }
  }

  if (identical_pair) {
    std::cout << "NO\n";
    return;
  }

  std::vector<bool> cycle_visited(n);
  auto is_cyclic = [&](this auto&& self, int u, int p = -1) {
    if (cycle_visited[u]) {
      return 0;
    }

    cycle_visited[u] = true;
    int m = edges[u].size();
    if (m != 2) {
      return -1;
    }

    int v = edges[u][0] == p ? edges[u][1] : edges[u][0];
    int e = self(v, u);
    if (e == -1) {
      return e;
    }

    return e + 1;
  };

  std::vector<bool> chain_visited(n);
  auto is_chain = [&](this auto&& self, int u, int p = -1) {
    if (chain_visited[u]) {
      return false;
    }

    chain_visited[u] = true;
    int m = edges[u].size();
    if (m == 2) {
      int v = edges[u][0] == p ? edges[u][1] : edges[u][0];
      return self(v, u);
    }

    return m == 1;
  };

  for (int u = 0; u < n; ++u) {
    if (cycle_visited[u] || chain_visited[u]) {
      continue;
    }

    bool chain = is_chain(u);
    bool valid_cycle = is_cyclic(u) % 2 == 0;
    if (!chain && !valid_cycle) {
      std::cout << "NO\n";
      return;
    }
  }

  std::cout << "YES\n";
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
