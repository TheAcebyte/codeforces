#include <algorithm>
#include <cstdint>
#include <iostream>

using i64 = std::int64_t;

void solve() {
  int n;
  std::cin >> n;

  int max = 0;
  i64 sum = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    sum += x;
    max = std::max(x, max);
  }

  if (sum % 2 == 0 && 2 * max <= sum) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
