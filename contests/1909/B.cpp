#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

bool is_valid_modulo(const std::vector<i64> &a, i64 mod) {
  i64 first = -1;
  i64 second = -1;
  for (i64 x : a) {
    i64 remainder = x % mod;
    if (remainder == first || remainder == second) {
      continue;
    }

    if (first == -1) {
      first = remainder;
    } else if (second == -1) {
      second = remainder;
    } else {
      return false;
    }
  }

  return second != -1;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<i64> a(n);
  for (i64 &x : a) {
    std::cin >> x;
  }

  i64 mod = 2;
  while (!is_valid_modulo(a, mod)) {
    mod <<= 1;
  }

  std::cout << mod << '\n';
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
