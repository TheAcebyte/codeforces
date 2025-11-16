#include <algorithm>
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

  int min = std::min_element(a.begin(), a.end()) - a.begin();
  u64 gcd = 0;
  for (int i = 0; i < n; ++i) {
    if (i != min && a[i] % a[min] == 0) {
      gcd = std::gcd(a[i], gcd);
    }
  }

  if (gcd == a[min]) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
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
