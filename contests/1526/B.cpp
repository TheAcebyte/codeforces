#include <cstdint>
#include <iostream>

using i64 = std::int64_t;

int gcd(int a, int b, i64 &x, i64 &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  i64 x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - a / b * y1;
  return d;
}

int ceil(i64 a, i64 b) {
  int result = a / b;
  if (a % b != 0 && ((a < 0 && b < 0) || (a > 0 && b > 0))) {
    ++result;
  }

  return result;
}

int floor(i64 a, i64 b) {
  int result = a / b;
  if (a % b != 0 && ((a < 0 && b > 0) || (a < 0 && b > 0))) {
    --result;
  }

  return result;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int x;
    std::cin >> x;

    i64 x0, y0;
    gcd(11, 111, x0, y0);
    x0 *= x;
    y0 *= x;

    int kmin = ceil(-x0, 111);
    int kmax = floor(y0, 11);

    std::cout << (kmin <= kmax && kmin >= 0 ? "YES" : "NO") << '\n';
  }

  return 0;
}
