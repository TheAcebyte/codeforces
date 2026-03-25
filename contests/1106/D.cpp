#include <iostream>
#include <queue>
#include <vector>

using min_heap = std::priority_queue<int, std::vector<int>, std::greater<int>>;
using adjacency_list = std::vector<std::vector<int>>;

void solve() {
  int n, m;
  std::cin >> n >> m;

  adjacency_list edges(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  min_heap nodes;
  nodes.push(1);
  std::vector<bool> visited(n + 1);
  std::vector<int> result;
  result.reserve(n);

  while (!nodes.empty()) {
    int u = nodes.top();
    nodes.pop();
    if (visited[u]) {
      continue;
    }

    result.push_back(u);
    visited[u] = true;

    for (int v : edges[u]) {
      nodes.push(v);
    }
  }

  const char *separator = "";
  for (int u : result) {
    std::cout << separator << u;
    separator = " ";
  }
  std::cout << '\n';
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
