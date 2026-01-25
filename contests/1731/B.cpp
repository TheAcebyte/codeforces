#include <cstdint>
#include <iostream>

#define MOD 1000000007

using u64 = std::uint64_t;

void solve() {
  u64 n;
  std::cin >> n;

  u64 result = ((337 * ((n * (((n - 1) * (4 * n + 1)) % MOD)) % MOD)) % MOD +
               (2022 * ((n * n) % MOD)) % MOD) % MOD;
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
