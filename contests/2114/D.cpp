#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

using i64 = std::int64_t;

struct point {
  int x;
  int y;
};

constexpr i64 INF = std::numeric_limits<i64>::max();

template <typename T, std::size_t N, typename Compare = std::less<T>>
std::array<std::size_t, N> get_top_n(const std::vector<T> &a,
                                     Compare cmp = Compare()) {
  assert(a.size() >= N);
  constexpr std::size_t EMPTY = std::numeric_limits<std::size_t>::max();
  std::array<std::size_t, N> top;
  top.fill(EMPTY);

  std::size_t n = a.size();
  for (std::size_t i = 0; i < n; ++i) {
    if (top[N - 1] != EMPTY && cmp(a[top[N - 1]], a[i])) {
      continue;
    }

    std::size_t j = N - 1;
    top[j] = i;
    while (j > 0 && (top[j - 1] == EMPTY || !cmp(a[top[j - 1]], a[top[j]]))) {
      std::swap(top[j - 1], top[j]);
      --j;
    }
  }

  return top;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<point> points(n);
  for (auto &point : points) {
    std::cin >> point.x >> point.y;
  }

  if (n == 1) {
    int result = 1;
    std::cout << result << '\n';
    return;
  }

  auto cmp_gt_x = [](point a, point b) { return a.x > b.x; };
  auto cmp_lt_x = [](point a, point b) { return a.x < b.x; };
  auto cmp_gt_y = [](point a, point b) { return a.y > b.y; };
  auto cmp_lt_y = [](point a, point b) { return a.y < b.y; };
  std::array<std::array<std::size_t, 2>, 4> extremums{
      {get_top_n<point, 2>(points, cmp_lt_x),
       get_top_n<point, 2>(points, cmp_gt_x),
       get_top_n<point, 2>(points, cmp_lt_y),
       get_top_n<point, 2>(points, cmp_gt_y)}};

  i64 result = INF;
  for (int i = 0; i < 4; ++i) {
    std::size_t excluded = extremums[i][0];
    std::array<int, 4> local_extremums;
    for (int j = 0; j < 4; ++j) {
      local_extremums[j] =
          extremums[j][0] == excluded ? extremums[j][1] : extremums[j][0];
    }

    i64 x_min = points[local_extremums[0]].x;
    i64 x_max = points[local_extremums[1]].x;
    i64 y_min = points[local_extremums[2]].y;
    i64 y_max = points[local_extremums[3]].y;

    i64 dx = x_max - x_min + 1;
    i64 dy = y_max - y_min + 1;
    i64 area = dx * dy;
    if (area == n - 1) {
      area += std::min(dx, dy);
    }

    result = std::min(area, result);
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
