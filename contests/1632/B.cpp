#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

using u64 = std::uint64_t;

int msb(u64 n) {
  int i = -1;
  while (n > 0) {
    n >>= 1;
    ++i;
  }

  return i;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }

  int m = 1 << msb(n - 1);
  std::swap(p[0], p[m - 1]);

  const char* separator = "";
  for (int x : p) {
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
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  while (T-- > 0) {
    solve();
  }

  return 0;
}
