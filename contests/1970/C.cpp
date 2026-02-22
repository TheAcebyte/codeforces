#include <iostream>
#include <vector>

bool can_win(const std::vector<std::vector<int>> &adjacency_list, int u,
             int p = -1) {
  for (int v : adjacency_list[u]) {
    if (p != v && !can_win(adjacency_list, v, u)) {
      return true;
    }
  }

  return false;
}

void solve() {
  int n, t;
  std::cin >> n >> t;

  std::vector<std::vector<int>> adjacency_list(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u;
    --v;

    adjacency_list[u].push_back(v);
    adjacency_list[v].push_back(u);
  }

  int u;
  std::cin >> u;
  --u;

  bool is_ron_winner = can_win(adjacency_list, u);
  if (is_ron_winner) {
    std::cout << "Ron\n";
  } else {
    std::cout << "Hermione\n";
  }
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
