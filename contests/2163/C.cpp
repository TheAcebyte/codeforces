#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n;
  std::cin >> n;

  std::array<std::vector<int>, 2> a;
  for (auto &row : a) {
    row.resize(n);
    for (int &x : row) {
      std::cin >> x;
    }
  }

  std::vector<int> prefix_min(n);
  std::vector<int> prefix_max(n);
  prefix_min[0] = prefix_max[0] = a[0][0];
  for (int i = 1; i < n; ++i) {
    prefix_min[i] = std::min(a[0][i], prefix_min[i - 1]);
    prefix_max[i] = std::max(a[0][i], prefix_max[i - 1]);
  }

  std::vector<int> suffix_min(n);
  std::vector<int> suffix_max(n);
  suffix_min[n - 1] = suffix_max[n - 1] = a[1][n - 1];
  for (int i = n - 2; i >= 0; --i) {
    suffix_min[i] = std::min(a[1][i], suffix_min[i + 1]);
    suffix_max[i] = std::max(a[1][i], suffix_max[i + 1]);
  }

  std::vector<std::vector<int>> openings(2 * n + 1);
  std::multiset<int> closings;
  for (int i = 0; i < n; ++i) {
    int l = std::min(prefix_min[i], suffix_min[i]);
    int r = std::max(prefix_max[i], suffix_max[i]);
    openings[l].push_back(r);
    closings.insert(r);
  }

  i64 result = 0;
  for (int l = 1; l <= 2 * n && !closings.empty(); ++l) {
    int min_r = *closings.begin();
    result += 2 * n - min_r + 1;
    for (int r : openings[l]) {
      auto it = closings.find(r);
      closings.erase(it);
    }
  }

  std::cout << result << '\n';
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
