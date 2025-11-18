#include <cstdint>
#include <iostream>
#include <vector>

#define N 10000000

using u64 = std::uint64_t;

std::vector<bool> sieves(N + 1, true);
std::vector<int> primes;

void solve() {
  int n;
  std::cin >> n;

  int p = -1;
  int left = 0;
  int right = primes.size() - 1;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (primes[middle] <= n) {
      p = middle;
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }

  int result = 0;
  for (int i = 1; i <= n; ++i) {
    while (p >= 0 && i * primes[p] > n) {
      --p;
    };

    result += p + 1;
  }

  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  sieves[0] = sieves[1] = false;
  for (u64 i = 2; i <= N; ++i) {
    if (!sieves[i]) {
      continue;
    }

    primes.push_back(i);
    for (u64 j = i * i; j <= N; j += i) {
      sieves[j] = false;
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
