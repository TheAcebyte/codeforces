#include <cstdint>
#include <iostream>

using u64 = std::uint64_t;

void solve() {
  u64 a, b;
  std::cin >> a >> b;

  u64 k;
  if (a % 2 == 1 && b % 2 == 1) {
    k = b;
  } else if ((a % 2 == 0 && b % 2 == 0) || (a % 2 == 1 && b % 4 == 0)) {
    k = b / 2;
  } else {
    std::cout << -1 << '\n';
    return;
  }

  u64 result = a * k + b / k;
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
