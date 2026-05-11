#include <cmath>
#include <vector>

struct point {
  double x;
  double y;
};

double area(const std::vector<point>& polygon) {
  int n = polygon.size();
  double area = 0.0;
  for (int i = 0; i < n; ++i) {
    auto p = polygon[i];
    auto q = i ? polygon[i - 1] : polygon[n - 1];
    area += (p.x - q.x) * (p.y + q.y);
  }

  area = std::fabs(area) / 2;
  return area;
}
