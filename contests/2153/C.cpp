#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>

using i64 = std::int64_t;

constexpr i64 zero = 0;

void solve() {
  int n;
  std::cin >> n;

  i64 base_perimeter = 0;
  int sides = 0;
  std::set<i64> points;
  for (int i = 0; i < n; ++i) {
    i64 x;
    std::cin >> x;

    auto it = points.find(x);
    if (it == points.end()) {
      points.insert(x);
    } else {
      points.erase(x);
      base_perimeter += 2 * x;
      sides += 2;
    }
  }

  i64 max_perimeter = 0;
  if (sides > 2) {
    max_perimeter = base_perimeter;
  }

  for (i64 x : points) {
    if (x < base_perimeter) {
      i64 perimeter = base_perimeter + x;
      max_perimeter = std::max(perimeter, max_perimeter);
    }

    i64 min_x = std::max(x - base_perimeter, zero);
    i64 max_x = base_perimeter + x;
    auto it = points.lower_bound(max_x);

    if (it == points.begin()) {
      continue;
    }

    --it;
    if (*it == x) {
      if (it == points.begin()) {
        continue;
      }

      --it;
    }

    i64 y = *it;
    if (y <= min_x || y >= max_x) {
      continue;
    }

    i64 perimeter = base_perimeter + x + y;
    max_perimeter = std::max(perimeter, max_perimeter);
  }

  std::cout << max_perimeter << '\n';
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
