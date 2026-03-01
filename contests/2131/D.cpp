#include <algorithm>
#include <iostream>
#include <vector>

int calculate_cost(const std::vector<std::vector<int>> &adjacency_list, int u,
                   int p, int r) {
  int m = adjacency_list[u].size();
  if (u != r && m == 1) {
    return p != r;
  }

  int cost = 0;
  for (int v : adjacency_list[u]) {
    if (v == p) {
      continue;
    }

    cost += calculate_cost(adjacency_list, v, u, r);
  }

  return cost;
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

  int root = -1;
  int root_leaves = 0;
  for (int u = 0; u < n; ++u) {
    auto predicate = [&](int v) {
      return adjacency_list[v].size() == 1;
    };

    int leaves = std::count_if(adjacency_list[u].begin(),
                               adjacency_list[u].end(), predicate);

    if (leaves > root_leaves) {
      root = u;
      root_leaves = leaves;
    }
  }

  int result = calculate_cost(adjacency_list, root, -1, root);
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
