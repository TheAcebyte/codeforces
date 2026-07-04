#include <iostream>
#include <vector>

using adjacency_list = std::vector<std::vector<int>>;

template<typename T>
void setmax(T& x, const T& y) { if (y > x) x = y; }

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

  std::vector<int> p(n + 1);
  std::vector<int> depth(n + 1);
  std::vector<int> max_depth(n + 1);

  std::vector<int> order;
  order.reserve(n);
  order.push_back(1);

  int head = 0;
  while (head < (int)order.size()) {
    int u = order[head++];
    max_depth[u] = depth[u];

    for (int v : edges[u]) {
      if (v == p[u]) continue;
      p[v] = u;
      depth[v] = depth[u] + 1;
      order.push_back(v);
    }
  }

  for (int i = n - 1; i >= 0; --i) {
    int u = order[i];
    if (u == 1) continue;
    setmax(max_depth[p[u]], max_depth[u]); 
  }

  std::vector<int> diff(n + 1);
  for (int u = 1; u <= n; ++u) {
    ++diff[depth[u]];
    --diff[max_depth[u] + 1];
  }

  int nodes = 0;
  int max_nodes = 0;
  for (int i = 0; i <= n; ++i) {
    nodes += diff[i];
    setmax(max_nodes, nodes);
  }

  int min_deletions = n - max_nodes;
  std::cout << min_deletions << '\n';
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
