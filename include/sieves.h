#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

using i64 = std::int64_t;

class sieves {
private:
  std::vector<std::size_t> primes;

public:
  sieves(std::size_t n) {
    std::vector<bool> primality(n + 1, true);
    primality[0] = primality[1] = false;
    for (std::size_t i = 0; i <= n; ++i) {
      if (!primality[i]) {
        continue;
      }

      primes.push_back(i);
      if ((i64)i * i > n) {
        continue;
      }

      for (std::size_t j = i * i; j <= n; j += i) {
        primality[j] = false;
      }
    }
  }

  const std::vector<std::size_t> &get_primes() const { return primes; }
};
