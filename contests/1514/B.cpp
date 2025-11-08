#include <cstdint>
#include <iostream>

#define MOD 1000000007

using u64 = std::uint64_t;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  while (T-- > 0) {
    int n, k;
    std::cin >> n >> k;

    u64 result = 1;
    for (int i = 0; i < k; ++i) {
      result = (result * n) % MOD;
    }
    std::cout << result << '\n';
  }

  return 0;
}
