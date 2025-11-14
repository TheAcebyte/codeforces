#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

using u64 = std::uint64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<u64> a(n);
  for (u64 &x : a) {
    std::cin >> x;
  }

  u64 even = a[0];
  u64 odd = a[1];
  for (int i = 2; i < n; ++i) {
    if (i & 1) {
      odd = std::gcd(odd, a[i]);
    } else {
      even = std::gcd(even, a[i]);
    }
  }

  bool evenDivisible = false;
  bool oddDivisible = false;
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      oddDivisible |= a[i] % even == 0;
    } else {
      evenDivisible |= a[i] % odd == 0;
    }
  }

  if (evenDivisible && oddDivisible) {
    std::cout << 0 << '\n';
  } else if (evenDivisible) {
    std::cout << even << '\n';
  } else {
    std::cout << odd << '\n';
  }
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
