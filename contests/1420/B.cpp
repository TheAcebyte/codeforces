#include <array>
#include <cstdint>
#include <iostream>

using u64 = std::uint64_t;

int msb(int n) {
  int i = 0;
  for (int j = 0; n > 0; ++j, n >>= 1) {
    if (n & 1) {
      i = j;
    }
  }

  return i;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    std::cin >> n;

    std::array<int, 32> count{};
    u64 result = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      result += count[msb(x)]++;
    }

    std::cout << result << '\n';
  }

  return 0;
}
