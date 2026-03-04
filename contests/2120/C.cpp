#include <cstdint>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n;
  i64 m;
  std::cin >> n >> m;

  i64 min = n;
  i64 max = (i64)n * (n + 1) / 2;
  if (m < min || m > max) {
    std::cout << -1 << '\n';
    return;
  }

  int starting_x = 0;
  for (int x = 1; x <= n; ++x) {
    i64 d = (i64)x * (2 * n - x + 1) / 2;
    if (d <= m) {
      starting_x = x;
    }
  }

  std::vector<int> nodes(n);
  std::iota(nodes.rbegin(), nodes.rbegin() + starting_x - 1, 1);
  std::iota(nodes.begin(), nodes.end() - starting_x + 1, starting_x);

  i64 d = (i64)starting_x * (2 * n - starting_x + 1) / 2;
  int swaps = m - d;
  for (int i = 0; i < swaps; ++i) {
    std::swap(nodes[i], nodes[i + 1]);
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
