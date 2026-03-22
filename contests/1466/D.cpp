#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

struct node {
  int weight;
  int edges;

  bool operator<(const node &other) { return weight < other.weight; }
};

void solve() {
  int n;
  std::cin >> n;

  i64 total_weight = 0;
  std::vector<node> nodes(n);
  for (auto &node : nodes) {
    std::cin >> node.weight;
    total_weight += node.weight;
  }

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u;
    --v;

    ++nodes[u].edges;
    ++nodes[v].edges;
  }

  std::sort(nodes.rbegin(), nodes.rend());
  i64 result = total_weight;
  int i = 0;
  const char *separator = "";
  for (int k = 1; k < n; ++k) {
    std::cout << separator << result;
    separator = " ";

    while (i < n && nodes[i].edges < 2) {
      ++i;
    }

    if (i < n) {
      result += nodes[i].weight;
      --nodes[i].edges;
    }
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
