#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

template <i64 N> class sieves {
private:
  std::vector<i64> primes;

public:
  sieves() {
    std::vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (i64 i = 0; i <= N; ++i) {
      if (!is_prime[i]) {
        continue;
      }

      primes.push_back(i);
      if ((i64)i * i > N) {
        continue;
      }

      for (i64 j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }

  const std::vector<i64> &get_primes() const { return primes; }
};

#define N 6000000

sieves<N> s;
const auto &primes = s.get_primes();

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }
  std::sort(a.rbegin(), a.rend());

  int result = 0;
  i64 coins = 0;
  for (int i = 0; i < n; ++i) {
    coins += a[i] - primes[i];
    if (coins < 0) {
      result = n - i;
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
