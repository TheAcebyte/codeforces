#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> children(n);
  for (int u = 1; u < n; ++u) {
    int p;
    std::cin >> p; 
    --p;
    children[p].push_back(u);
  }

  int m;
  std::cin >> m;
  std::vector<bool> dams(n);
  for (int i = 0; i < m; ++i) {
    int u;
    std::cin >> u;
    --u;
    dams[u] = true;
  }

  std::vector<int> cameras;
  auto dfs = [&](this auto&& self, int u) -> bool {
    std::vector<int> children_with_dams;
    for (int v : children[u]) {
      if (self(v)) {
        children_with_dams.push_back(v);
      }
    }

    int size = children_with_dams.size();
    if (size >= 1) {
      for (int i = 1; i < size; ++i) {
        int v = children_with_dams[i];
        cameras.push_back(v);
      }

      if (dams[u]) {
        int v = children_with_dams.front();
        cameras.push_back(v);
      }
    }

    return size >= 1 || dams[u];
  };

  dfs(0);
  std::cout << cameras.size();
  for (int u : cameras) {
    std::cout << ' ' << u + 1;
  }
  std::cout << '\n';
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
