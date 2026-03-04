#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

constexpr i64 root = 1;
constexpr i64 zero = 0;

void store_threats(const std::vector<std::vector<int>> &adjacency_list,
                   const std::vector<int> &dangers, std::vector<i64> &min,
                   std::vector<i64> &max, int u, int p = 0) {
  min[u] = std::min(dangers[u] - max[p], zero);
  max[u] = dangers[u] - min[p];
  for (int v : adjacency_list[u]) {
    if (v != p) {
      store_threats(adjacency_list, dangers, min, max, v, u);
    }
  }
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> dangers(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> dangers[i];
  }

  std::vector<std::vector<int>> adjacency_list(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;

    adjacency_list[u].push_back(v);
    adjacency_list[v].push_back(u);
  }

  std::vector<i64> min(n + 1);
  std::vector<i64> max(n + 1);
  store_threats(adjacency_list, dangers, min, max, root);

  const char *separator = "";
  for (int i = 1; i <= n; ++i) {
    i64 threat = max[i];
    std::cout << separator << threat;
    separator = " ";
  }
  std::cout << '\n';
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
