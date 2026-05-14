#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

constexpr int inf = 1e8;
constexpr double error = 1e-6;

template<typename T>
void setmin(T &x, T y) { x = std::min(x, y); }

template<typename T>
void setmax(T &x, T y) { x = std::max(x, y); }

struct person {
  int x;
  int t;
};

void solve() {
  int n;
  std::cin >> n;

  int min_x = inf;
  int max_x = 0;
  std::vector<person> people(n);
  for (auto &p : people) {
    std::cin >> p.x;
    setmin(min_x, p.x);
    setmax(max_x, p.x);
  }

  for (auto &p : people) {
    std::cin >> p.t;
  }

  auto calculate_meeting_time = [&](double x0) {
    double max_t = 0;
    for (auto p : people) {
      double t = p.t + std::abs(p.x - x0);
      setmax(max_t, t);
    }

    return max_t;
  };

  double l = min_x;
  double r = max_x;
  while (r - l > error) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    double f1 = calculate_meeting_time(m1);
    double f2 = calculate_meeting_time(m2);
    if (f1 > f2) {
      l = m1;
    } else {
      r = m2;
    }
  }


  double result = l;
  std::cout << std::fixed << std::setprecision(6) << result << '\n';
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
