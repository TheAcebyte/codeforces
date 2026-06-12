#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

int mod(int i, int n) {
  int j = i % n;
  return j < 0 ? j + n : j;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> h(n);
  for (int& x : h) std::cin >> x;

  for (int l = 0; l < n; ++l) {
    std::vector<int> prefix_max(n);
    for (int i = 0; i < n; ++i) {
      int j = mod(l + i + 1, n);
      int k = mod(j - 1, n);
      prefix_max[j] = std::max(prefix_max[k], h[k]);
    }

    std::vector<int> suffix_max(n);
    for (int i = 0; i < n; ++i) {
      int j = mod(l - i - 1, n);
      int k = mod(j + 1, n);
      suffix_max[j] = std::max(suffix_max[k], h[j]);
    }

    i64 sum = 0;
    for (int i = 0; i < n; ++i) {
      if (i == l) continue;
      int max_weight = std::min(prefix_max[i], suffix_max[i]);
      sum += max_weight;
    }

    std::cout << sum << " \n"[l == n - 1];
  }
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
