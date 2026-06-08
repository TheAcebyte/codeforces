#pragma once

#include <cassert>
#include <cstddef>
#include <cstdint>
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
      if (i * i > n) {
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
