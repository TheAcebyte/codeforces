#include <array>
#include <iostream>
#include <unordered_map>
#include <vector>

#define N 1000

std::array<std::vector<int>, N + 1> divisors;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::unordered_map<int, int> seen;
  int result = -1;
  for (int i = n - 1; i >= 0; --i) {
    int j = i + 1;
    if (a[i] == 1) {
      result = std::max(2 * j, result);
    } else {
      for (int divisor : divisors[a[i]]) {
        if (seen.find(divisor) == seen.end()) {
          seen[divisor] = j;
        } else {
          result = std::max(j + seen[divisor], result);
        }
      }
    }
  }

  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::array<int, N + 1> sieves;
  std::vector<int> primes;

  sieves.fill(true);
  sieves[0] = sieves[1] = false;
  for (int i = 0; i <= N; ++i) {
    if (!sieves[i]) {
      continue;
    }

    primes.push_back(i);
    for (int j = 2 * i; j <= N; j += i) {
      sieves[j] = false;
    }
  }

  for (int i = 2; i <= N; ++i) {
    for (int prime : primes) {
      if (prime > i) {
        break;
      }

      if (i % prime == 0) {
        divisors[i].push_back(prime);
      }
    }
  }

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  while (T-- > 0) {
    solve();
  }

  return 0;
}
