#include <cstdint>
#include <iostream>

#define MOD 1000000007

using u64 = std::uint64_t;

void solve() {
  int n;
  std::cin >> n;

  u64 factorial = 1;
  for (int i = 1; i <= n; ++i) {
    factorial = (factorial * i) % MOD;
  }

  int result = (((factorial * n) % MOD) * (n - 1)) % MOD;
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
