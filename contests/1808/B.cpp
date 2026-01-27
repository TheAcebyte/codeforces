#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> cards(m, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> cards[j][i];
    }
  }

  u64 result = 0;
  for (auto& column : cards) {
    std::sort(column.begin(), column.end());
    for (int i = 0; i < n; ++i) {
      result += (u64)(2 * i - n + 1) * column[i];
    }
  }

  std::cout << result << '\n';
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
