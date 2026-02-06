#include <cassert>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

class Sieves {
private:
  std::vector<std::size_t> primes;

public:
  Sieves(std::size_t n) {
    std::vector<bool> sieves(n + 1, true);
    sieves[0] = sieves[1] = false;
    for (std::size_t i = 0; i <= n; ++i) {
      if (!sieves[i]) {
        continue;
      }

      primes.push_back(i);
      if ((u64)i * i > n) {
        continue;
      }

      for (std::size_t j = i * i; j <= n; j += i) {
        sieves[j] = false;
      }
    }
  }

  const std::vector<std::size_t> &getPrimes() const { return primes; }
};

#define N 25000
#define D 3

Sieves sieves(N);

void solve() {
  int d;
  std::cin >> d;

  const auto& primes = sieves.getPrimes();
  std::vector<int> divisors{1};
  while (divisors.size() < D) {
    int x = divisors.back() + d;
    int y = -1;
    int l = 0;
    int r = primes.size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      int p = primes[m];
      if (p >= x) {
        y = p;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    assert(y != -1);
    divisors.push_back(y);
  }

  int result = 1;
  for (int divisor : divisors) {
    result *= divisor;
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
