#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void fill_bipartite_set(const std::vector<std::vector<int>> &adjacency_list,
                        std::vector<int> &sets, int u = 0, int set = 0) {
  if (sets[u] != -1) {
    return;
  }

  sets[u] = set;
  int other_set = set == 0 ? 1 : 0;
  for (int v : adjacency_list[u]) {
    fill_bipartite_set(adjacency_list, sets, v, other_set);
  }
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adjacency_list(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u;
    --v;

    adjacency_list[u].push_back(v);
    adjacency_list[v].push_back(u);
  }

  std::vector<int> sets(n, -1);
  fill_bipartite_set(adjacency_list, sets);

  i64 first_set_size = std::count(sets.begin(), sets.end(), 0);
  i64 second_set_size = std::count(sets.begin(), sets.end(), 1);

  i64 result = first_set_size * second_set_size - n + 1;
  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  solve();

  return 0;
}
