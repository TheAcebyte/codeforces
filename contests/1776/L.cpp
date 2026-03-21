#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>

using i64 = std::int64_t;

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  i64 x = 0;
  i64 y = 0;
  for (char c : s) {
    if (c == '+') {
      ++x;
    } else {
      ++y;
    }
  }

  if (x < y) {
    std::swap(x, y);
  }

  int q;
  std::cin >> q;
  while (q-- > 0) {
    i64 a, b;
    std::cin >> a >> b;

    if (a > b) {
      std::swap(a, b);
    }

    if (a == b) {
      if (x == y) {
        std::cout << "YES\n";
      } else {
        std::cout << "NO\n";
      }
    } else {
      i64 lcm = std::lcm(a, b);
      i64 d1 = lcm / a;
      i64 d2 = lcm / b;

      if ((x - y) % (d1 - d2) == 0) {
        i64 k = (x - y) / (d1 - d2);
        i64 o = x - d1 * k;
        if (o >= 0 && o <= y) {
          std::cout << "YES\n";
        } else {
          std::cout << "NO\n";
        }
      } else {
        std::cout << "NO\n";
      }
    }
  }
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  solve();

  return 0;
}
