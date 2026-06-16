#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using i64 = std::int64_t;

constexpr i64 M = 1e9 + 7;

void solve() {
  int n, x;
  std::cin >> n >> x;

  std::vector<int> a(n);
  for (int& x : a) std::cin >> x;

  std::map<int, i64> primes;
  auto add_prime = [&](int p) {
    if (primes.find(p) == primes.end()) {
      primes[p] = 1;
    }

    ++primes[p];
  };

  for (int& x : a) {
    int d = 2;
    for (; d * d <= x; ++d) {
      while (x % d == 0) {
        add_prime(d);
        x /= d;
      }
    }

    if (x > 1) {
      add_prime(x);
    }
  }

  i64 result = 1;
  for (auto [p, c] : primes) {
    result = (result * c) % M;
  }

  std::cout << result << '\n';
}

int main() {
#ifndef ONLINE_JUDGE 
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t-- > 0) {
    solve();
  }

  return 0;
}
