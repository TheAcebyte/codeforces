#pragma once

#include <cassert>
#include <cstddef>
#include <cstdint>
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
