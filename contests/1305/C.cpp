#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n);
  for (int& x : a) std::cin >> x;

  if (n > m) {
    std::cout << 0 << '\n';
    return;
  }

  i64 result = 1; 
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      result = (result * std::abs(a[i] - a[j])) % m;
    }
  }

  std::cout << result << '\n';
}

int main() {
#ifndef ONLINE_JUDGE 
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
