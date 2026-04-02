#include <algorithm>
#include <iostream>
#include <vector>

struct interval {
  int l;
  int r;

  bool operator<(const interval& other) const { return l < other.l; }
};

void solve() {
  int n;
  std::cin >> n;

  std::vector<interval> intervals(n);
  for (auto &interval : intervals) {
    std::cin >> interval.l >> interval.r;
  }
  std::sort(intervals.begin(), intervals.end());

  int last_r1 = -1;
  int last_r2 = -1;
  for (auto interval : intervals) {
    if (interval.l > last_r1) {
      last_r1 = interval.r;
    } else if (interval.l > last_r2) {
      last_r2 = interval.r;
    } else {
      std::cout << "NO\n";
      return;
    }
  }

  std::cout << "YES\n";
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
