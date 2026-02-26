#include <cassert>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using i64 = std::int64_t;

template <i64 N> class sieves {
private:
  std::vector<i64> primes;
  std::vector<i64> spf;

public:
  sieves() : spf(N + 1) {
    std::vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (i64 i = 0; i <= N; ++i) {
      if (!is_prime[i]) {
        continue;
      }

      primes.push_back(i);
      spf[i] = i;
      if ((i64)i * i > N) {
        continue;
      }

      for (i64 j = i * i; j <= N; j += i) {
        is_prime[j] = false;
        spf[j] = i;
      }
    }
  }

  const std::vector<i64> &get_primes() const { return primes; }

  i64 get_spf(i64 x) {
    assert(x >= 0 && x <= N);
    return spf[x];
  }
};

#define N 200001

sieves<N> sv;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> b(n);
  for (int &x : b) {
    std::cin >> x;
  }

  std::map<int, int> primes;
  for (int x : a) {
    while (x > 1) {
      int p = sv.get_spf(x);
      while (x % p == 0) {
        x /= p;
      }

      ++primes[p];
    }
  }

  for (auto [p, count] : primes) {
    if (count >= 2) {
      int result = 0;
      std::cout << result << '\n';
      return;
    }
  }

  for (int x : a) {
    int y = x + 1;
    while (y > 1) {
      int p = sv.get_spf(y);
      while (y % p == 0) {
        y /= p;
      }

      if (primes[p]) {
        int result = 1;
        std::cout << result << '\n';
        return;
      }
    }
  }

  int result = 2;
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
