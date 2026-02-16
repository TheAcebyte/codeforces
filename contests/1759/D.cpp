#include <cstdint>
#include <cstdlib>
#include <iostream>

using i64 = std::int64_t;

void solve() {
  int n, m;
  std::cin >> n >> m;

  int x = n;
  int twos = 0;
  while (x % 2 == 0) {
    ++twos;
    x /= 2;
  }

  int fives = 0;
  while (x % 5 == 0) {
    ++fives;
    x /= 5;
  }

  i64 k = 1;
  int difference = std::abs(twos - fives);
  int lower_factor = twos < fives ? 2 : 5;
  while (difference > 0 && k * lower_factor <= m) {
    k *= lower_factor;
    --difference;
  }

  while (k * 10 <= m) {
    k *= 10;
  }

  k *= m / k;
  i64 result = n * k;
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
