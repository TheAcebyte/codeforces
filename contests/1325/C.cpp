#include <iostream>
#include <vector>

struct edge {
  int u;
  int v;
  int label;
};

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> degree(n + 1);
  std::vector<edge> edges(n - 1);
  for (auto &edge : edges) {
    std::cin >> edge.u >> edge.v;
    ++degree[edge.u];
    ++degree[edge.v];
  }

  int root = 0;
  for (int u = 1; u <= n; ++u) {
    if (degree[u] >= 3) {
      root = u;
      break;
    }
  }

  int l = 0;
  int r = n - 2;
  for (auto &edge : edges) {
    bool is_root_edge = edge.u == root || edge.v == root;
    edge.label = is_root_edge ? l++ : r--;
  }

  for (const auto &edge : edges) {
    std::cout << edge.label << '\n';
  }
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
