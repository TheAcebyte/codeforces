#include <algorithm>
#include <cstdint>
#include <iostream>

using u64 = std::uint64_t;

u64 lsb(u64 n) {
  int i = 0;
  while (n > 0) {
    if (n & 1) {
      return i;
    }

    n >>= 1;
    ++i;
  }

  return -1;
}

void solve() {
  u64 a, b;
  std::cin >> a >> b;

  u64 min = std::min(a, b);
  u64 max = std::max(a, b);
  u64 x = max / min;
  if (max % min != 0 || (x & (x - 1)) != 0) {
    std::cout << -1 << '\n';
    return;
  }

  u64 bit = lsb(x);
  u64 result = bit / 3 + (bit % 3) / 2 + (bit % 3 % 2);
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
