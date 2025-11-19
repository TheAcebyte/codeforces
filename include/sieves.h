#pragma once

#include <cstddef>
#include <cstdint>
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
