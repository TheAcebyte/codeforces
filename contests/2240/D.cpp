#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, d;
  std::cin >> n >> d;
  
  std::vector<int> a(n);
  for (int& x : a) std::cin >> x;

  i64 subarray_sum = 0;
  int l = n - d;
  int r = d;
  for (int i = l;; i = (i + 1) % n) {
    subarray_sum += a[i];
    if (i == r) break;
  }

  i64 total_happiness = 0;
  for (int i = 0; i < n; ++i) {
    i64 sum_of_adjacents = subarray_sum - a[i];
    i64 net_happiness = (i64)2 * d * a[i] - sum_of_adjacents;
    total_happiness += std::max<i64>(net_happiness, 0);
    r = (r + 1) % n;
    subarray_sum += a[r] - a[l];
    l = (l + 1) % n;
  }

  std::cout << total_happiness << '\n';
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
