#include <algorithm>
#include <iostream>
#include <vector>

int get_tree_reading(
    const std::vector<std::vector<std::pair<int, int>>> &adjacency_list,
    int node = 0, int parent = -1, int parent_order = -1, int reading = 1) {
  int max_reading = reading;
  for (auto [neighbor, order] : adjacency_list[node]) {
    if (neighbor == parent) {
      continue;
    }

    bool preceding_read = order < parent_order;
    int neighbor_reading = get_tree_reading(adjacency_list, neighbor, node,
                                            order, reading + preceding_read);

    max_reading = std::max(neighbor_reading, max_reading);
  }

  return max_reading;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::vector<std::pair<int, int>>> adjacency_list(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u;
    --v;

    adjacency_list[u].push_back({v, i});
    adjacency_list[v].push_back({u, i});
  }

  int result = get_tree_reading(adjacency_list);
  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  while (T-- > 0) {
    solve();
  }

  return 0;
}
