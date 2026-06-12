#include <cstdint>
#include <iostream>

using i64 = std::int64_t;

void solve() {
  i64 n;
  std::cin >> n;

  if (n % 12 != 10) {
    i64 a = n % 12;
    i64 b = n - a;
    std::cout << a << ' ' << b << '\n';
  } else if (n >= 22) {
    i64 a = 22;
    i64 b = n - a;
    std::cout << a << ' ' << b << '\n';
  } else {
    std::cout << -1 << '\n';
    return;
  }
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
