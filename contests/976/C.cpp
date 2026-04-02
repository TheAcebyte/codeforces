#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

struct interval {
  int l;
  int r;
};

void solve() {
  int n;
  std::cin >> n;

  std::vector<interval> intervals(n);
  for (auto &interval : intervals) {
    std::cin >> interval.l >> interval.r;
  }

  std::vector<int> indices(n);
  std::iota(indices.begin(), indices.end(), 0);

  auto cmp = [&](int i, int j) {
    int l1 = intervals[i].l;
    int r1 = intervals[i].r;
    int l2 = intervals[j].l;
    int r2 = intervals[j].r;

    if (l1 < l2) return true;
    if (l1 > l2) return false;
    return r1 > r2;
  };

  std::sort(indices.begin(), indices.end(), cmp);

  int max_ri = -1;
  for (int i : indices) {
    if (max_ri == -1 || intervals[i].r > intervals[max_ri].r) {
      max_ri = i;
    } else {
      int j = i + 1;
      int k = max_ri + 1;
      std::cout << j << ' ' << k << '\n';
      return;
    }
  }

  std::cout << "-1 -1\n";
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
