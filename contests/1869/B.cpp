#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

struct Point {
  i64 x;
  i64 y;

  i64 distance(const Point &other) const {
    return std::abs(x - other.x) + std::abs(y - other.y);
  }
};

void solve() {
  int n, k, a, b;
  std::cin >> n >> k >> a >> b;
  --a;
  --b;

  std::vector<Point> cities(n);
  for (Point &city : cities) {
    std::cin >> city.x >> city.y;
  }

  const Point &cityA = cities[a];
  const Point &cityB = cities[b];
  i64 nearestMajorA = -1;
  i64 nearestMajorB = -1;
  for (int i = 0; i < k; ++i) {
    const Point &city = cities[i];

    i64 distanceToA = cityA.distance(city);
    if (nearestMajorA == -1 || distanceToA < nearestMajorA) {
      nearestMajorA = distanceToA;
    }

    i64 distanceToB = cityB.distance(city);
    if (nearestMajorB == -1 || distanceToB < nearestMajorB) {
      nearestMajorB = distanceToB;
    }
  }

  i64 result = cityA.distance(cityB);
  if (nearestMajorA >= 0 && nearestMajorB >= 0) {
    result = std::min(nearestMajorA + nearestMajorB, result);
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
