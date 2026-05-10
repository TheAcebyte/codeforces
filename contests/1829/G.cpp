#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>

#define R 2023

using i64 = std::int64_t;

constexpr int inf = 1e7;

i64 sum_squares(i64 n) {
  return n * (n + 1) * (2 * n + 1) / 6;
}

int find_row(int n) {
  int l = 1;
  int r = R;
  int row = 0;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (m * (m + 1) / 2 >= n) {
      row = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  assert(row > 0);
  return row;
}

void solve() {
  int n;
  std::cin >> n;

  int l = n;
  int r = n;
  auto update_bounds = [&](int x) {
    l = std::min(x, l);
    r = std::max(x, r);
  };

  i64 sum = 0;
  for (int row = find_row(n); row > 0; --row) {
    sum += sum_squares(r) - sum_squares(l - 1);
    int max = row * (row + 1) / 2;
    int min = max - row + 1;
    int old_l = l;
    int old_r = r;
    l = inf;
    r = -inf;
    if (old_l > min) update_bounds(old_l - row);
    if (old_l < max) update_bounds(old_l - row + 1);
    if (old_r > min) update_bounds(old_r - row);
    if (old_r < max) update_bounds(old_r - row + 1);
  }

  std::cout << sum << '\n';
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
