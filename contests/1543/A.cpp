#include <cstdint>
#include <cstdlib>
#include <iostream>

using i64 = std::int64_t;

i64 nearestMultiple(i64 x, i64 d) {
  i64 roundedUp = (x + d - 1) / d * d; 
  i64 roundedDown = x / d * d;
  if (x - roundedDown <= roundedUp - x) {
    return roundedDown;
  } else {
    return roundedUp;
  }
}

void solve() {
  i64 a, b;
  std::cin >> a >> b;

  if (a == b) {
    std::cout << 0 << ' ' << 0 << '\n';
    return;
  }

  i64 gcd = std::abs(a - b);
  i64 steps = std::abs(a - nearestMultiple(a, gcd));
  std::cout << gcd << ' ' << steps << '\n';
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
