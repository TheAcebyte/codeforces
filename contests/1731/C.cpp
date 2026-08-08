#include <cstdint>
#include <iostream>
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
  int n;
  std::cin >> n;
  int m = (1 << (msb(n) + 1)) - 1;

  std::vector<int> a(n);
  for (int& x : a) std::cin >> x;

  i64 odd_subarrays = 0;
  for (int j = 0; j * j <= m; ++j) {
    int d = j * j;
    std::vector<int> xor_count(m + 1);
    ++xor_count[0];
    int x = 0;
    for (int i = 0; i < n; ++i) {
      x ^= a[i];
      odd_subarrays += xor_count[x ^ d];
      ++xor_count[x];
    }
  }

  i64 even_subarrays = (i64)n * (n + 1) / 2 - odd_subarrays;
  std::cout << even_subarrays << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
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
