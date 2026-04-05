#include <algorithm>
#include <deque>
#include <iostream>
#include <set>
#include <vector>

struct node {
  int u;
  int p;
};

using adjacency_list = std::vector<std::vector<int>>;

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

  int result = 0;
  std::deque<node> queue{{1, 0}};
  while (!queue.empty()) {
    int m = queue.size();
    std::set<int> parents;
    for (int i = 0; i < m; ++i) {
      auto [u, p] = queue.front();
      queue.pop_front();
      parents.insert(p);

      for (int v : edges[u]) {
        if (v != p) {
          queue.push_back({v, u});
        }
      }
    }

    int level_size = m + (parents.size() == 1);
    result = std::max(level_size, result);
  }

  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
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
