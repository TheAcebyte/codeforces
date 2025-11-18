#include <array>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

using u64 = std::uint64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::array<u64, 30> bits;
  bits.fill(0);
  for (int x : a) {
    for (int i = 0; i < 30; ++i) {
      if ((x >> i) & 1) {
        ++bits[i];
      }
    }
  }

  u64 result = std::numeric_limits<u64>::min();
  for (int x : a) {
    u64 sum = 0;
    for (int i = 0; i < 30; ++i) {
      if ((x >> i) & 1) {
        sum += (n - bits[i]) * (1 << i);
      } else {
        sum += bits[i] * (1 << i);
      }
    }

    result = std::max(sum, result);
  }

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
