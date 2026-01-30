#include <iostream>
#include <cstddef>
#include <cstdint>
#include <map>
#include <vector>

#define N 1000000

using u64 = std::uint64_t;

class Sieves {
private:
  std::vector<std::size_t> divisors;

public:
  Sieves(std::size_t n) : divisors(n + 1) {
    std::vector<bool> sieves(n + 1, true);
    sieves[0] = sieves[1] = false;
    for (std::size_t i = 0; i <= n; ++i) {
      if (!sieves[i]) {
        continue;
      }

      divisors[i] = i;
      if ((u64)i * i > n) {
        continue;
      }

      for (std::size_t j = i * i; j <= n; j += i) {
        if (sieves[j]) {
          sieves[j] = false;
          divisors[j] = i;
        }
      }
    }
  }

  const std::vector<std::size_t> &getDivisors() const { return divisors; }
};

Sieves sieves(N);
const auto& divisors = sieves.getDivisors();

void solve() {
  int n;
  std::cin >> n;

  std::map<int, int> primes;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    while (x != 1) {
      int divisor = divisors[x];
      ++primes[divisor];
      x /= divisor;
    }
  }

  for (auto [prime, count] : primes) {
    if (count % n != 0) {
      std::cout << "NO\n";
      return;
    }
  }

  std::cout << "YES\n";
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
