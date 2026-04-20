#include <cstdint>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using i64 = std::int64_t;

int msb(int n) {
  int i = -1;
  while (n > 0) {
    ++i;
    n >>= 1;
  }

  return i;
}

void solve() {
  int l, r;
  std::cin >> l >> r;

  std::vector<int> a(r + 1);
  std::iota(a.begin(), a.end(), 0);

  int i = r;
  while (i > 0) {
    int m = msb(i);
    int x = (1 << (m + 1)) - 1;
    int j = x & ~i;
    int next_i = j - 1;
    while (i > j) {
      std::swap(a[i--], a[j++]);
    }

    i = next_i;
  }

  i64 result = 0;
  for (int i = 0; i <= r; ++i) {
    result += a[i] | i;
  }

  std::cout << result << '\n';
  const char *separator = "";
  for (int x : a) {
    std::cout << separator << x;
    separator = " ";
  }
  std::cout << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t-- > 0) {
    solve();
  }

  return 0;
}
