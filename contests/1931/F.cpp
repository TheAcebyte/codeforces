#include <cassert>
#include <iostream>
#include <map>
#include <vector>

template <typename T>
class graph {
private:
  std::map<T, std::vector<T>> adjacency_list;

  bool _cycle_dfs(T u, std::map<T, int> &visited) {
    if (visited[u] == 2) return false;
    if (visited[u] == 1) return true;
    visited[u] = 1;
    for (int v : adjacency_list[u]) {
      if (_cycle_dfs(v, visited)) {
        return true;
      }
    }

    visited[u] = 2;
    return false;
  }

public:
  void add_edge(T u, T v) {
    adjacency_list[u].push_back(v);
  }

  bool is_cyclic() {
    assert(adjacency_list.size() > 0);
    std::map<T, int> visited;
    for (auto [u, _] : adjacency_list) {
      if (_cycle_dfs(u, visited)) {
        return true;
      }
    }

    return false;
  }
};

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<std::vector<int>> a(k, std::vector<int>(n));
  for (auto &row : a) for (int &x : row) std::cin >> x;

  if (n <= 2) {
    std::cout << "YES" << '\n';
    return;
  }

  graph<int> g;
  for (int i = 0; i < k; ++i) {
    for (int j = 1; j < n - 1; ++j) {
      g.add_edge(a[i][j], a[i][j + 1]);
    }
  }

  std::cout << (g.is_cyclic() ? "NO" : "YES") << '\n';
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
