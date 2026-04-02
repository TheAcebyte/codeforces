#include <iostream>
#include <vector>

using adjacency_list = std::vector<std::vector<int>>;

int count_deletable_edges(const adjacency_list &edges, int u, int p,
                          int &result) {
  int set_size = 1;
  for (int v : edges[u]) {
    if (v == p) {
      continue;
    }

    int neighbor_set_size = count_deletable_edges(edges, v, u, result);
    if (neighbor_set_size % 2 == 0) {
      ++result;
    }

    set_size += neighbor_set_size;
  }

  return set_size;
}

void solve() {
  int n;
  std::cin >> n;

  adjacency_list edges(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  if (n & 1) {
    std::cout << -1 << '\n';
    return;
  }

  int result = 0;
  count_deletable_edges(edges, 1, 0, result);
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
