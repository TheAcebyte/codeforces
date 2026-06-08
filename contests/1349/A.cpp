#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using i64 = std::int64_t;

class sieves {
private:
  i64 n;
  std::vector<i64> primes;
  std::vector<i64> spf;

public:
  sieves(i64 n) : n(n), spf(n + 1) {
    std::vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (i64 i = 0; i <= n; ++i) {
      if (!is_prime[i]) {
        continue;
      }

      primes.push_back(i);
      spf[i] = i;
      if ((i64)i * i > n) {
        continue;
      }

      for (i64 j = i * i; j <= n; j += i) {
        is_prime[j] = false;
        spf[j] = i;
      }
    }
  }

  const std::vector<i64> &get_primes() const { return primes; }

  i64 get_spf(i64 x) {
    assert(x >= 0 && x <= n);
    return spf[x];
  }
};

constexpr int N = 200000;
sieves s(N);

struct multiple {
  int count;
  int first = -1;
  int second = -1;

  void add(int x) {
    assert(x >= 0);
    ++count;
    if (first == -1 || x < first) {
      second = first;
      first = x;
    } else if (second == -1 || x < second) {
      second = x;
    }
  }

  int get_2nd_smallest(int n) {
    if (count == n) return second;
    if (count == n - 1) return first;
    return 1;
  }
};

void solve() {
  int n;
  std::cin >> n;

  std::map<int, multiple> multiples;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    while (x > 1) {
      int p = s.get_spf(x);
      int y = 1;
      while (x % p == 0) {
        y *= p;
        x /= p;
      }

      multiples[p].add(y);
    }
  }

  i64 gcd = 1;
  for (auto [p, m] : multiples) {
    gcd *= m.get_2nd_smallest(n);
  }

  std::cout << gcd << '\n';
}

int main() {
#ifndef ONLINE_JUDGE 
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
