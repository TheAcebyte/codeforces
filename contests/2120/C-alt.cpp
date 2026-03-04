#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  i64 n, m;
  std::cin >> n >> m;

  i64 min = n;
  i64 max = n * (n + 1) / 2;
  if (m < min || m > max) {
    std::cout << -1 << '\n';
    return;
  }

  i64 p = m - n;
  std::vector<int> nodes;
  std::vector<bool> seen(n + 1);
  for (int i = n - 1; i > 0; --i) {
    if (i <= p) {
      int u = i + 1;
      nodes.push_back(u);
      seen[u] = true;
      p -= i;
    }
  }

  nodes.push_back(1);
  for (int u = 2; u <= n; ++u) {
    if (!seen[u]) {
      nodes.push_back(u);
    }
  }

  int root = nodes[0];
  std::cout << root << '\n';
  for (int i = 0; i < n - 1; ++i) {
    int u = nodes[i];
    int v = nodes[i + 1];
    std::cout << u << ' ' << v << '\n';
  }
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
