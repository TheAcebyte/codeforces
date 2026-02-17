#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adjacency_list(n);
  std::vector<int> c(n);
  for (int v = 0; v < n; ++v) {
    int u;
    std::cin >> u >> c[v];
    --u;

    if (u >= 0) {
      adjacency_list[u].push_back(v);
    }
  }

  std::vector<int> deleted;
  for (int u = 0; u < n; ++u) {
    if (!c[u]) {
      continue;
    }

    bool deletable = true;
    for (int v : adjacency_list[u]) {
      if (!c[v]) {
        deletable = false;
        break;
      }
    }

    if (deletable) {
      deleted.push_back(u);
    }
  }

  if (deleted.empty()) {
    std::cout << -1 << '\n';
    return;
  }

  std::sort(deleted.begin(), deleted.end());
  const char* separator = "";
  for (int u : deleted) {
    std::cout << separator << u + 1;
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
  solve();

  return 0;
}
