#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> points;
  std::set<int> unpaired;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;

    auto it = unpaired.find(a);
    if (it == unpaired.end()) {
      unpaired.insert(a);
    } else {
      points.push_back(a);
      unpaired.erase(it);
    }
  }

  int m = points.size();
  if (m < 4) {
    std::cout << "NO\n";
    return;
  }

  std::sort(points.begin(), points.end());
  int x_min = points[0];
  int y_min = points[1];
  int x_max = points[m - 2];
  int y_max = points[m - 1];

  int x1 = x_min;
  int y1 = y_min;
  int x2 = x_min;
  int y2 = y_max;
  int x3 = x_max;
  int y3 = y_min;
  int x4 = x_max;
  int y4 = y_max;

  std::cout << "YES\n";
  std::cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' '
            << y3 << ' ' << x4 << ' ' << y4 << '\n';
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
