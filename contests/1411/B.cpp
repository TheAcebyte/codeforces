#include <cstdint>
#include <iostream>

#define LCM 2520

using i64 = std::int64_t;

i64 mod(i64 a, i64 m) {
  i64 result = a % m;
  return result < 0 ? result + m : result;
}

bool is_fair(i64 x) {
  i64 y = x;
  while (y > 0) {
    int d = y % 10;
    if (d != 0 && x % d != 0) {
      return false;
    }

    y /= 10;
  }

  return true;
}

void solve() {
  i64 n;
  std::cin >> n;

  i64 nearest = n + mod(LCM - n, LCM);
  i64 result = nearest;
  for (i64 x = n; x <= nearest; ++x) {
    if (is_fair(x)) {
      result = x;
      break;
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
