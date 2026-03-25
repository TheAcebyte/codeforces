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
  auto cmp = [&](int i, int j) { return intervals[i].l < intervals[j].l; };
  std::sort(indices.begin(), indices.end(), cmp);

  auto get_l = [&](int i) { return intervals[indices[i]].l; };
  auto get_r = [&](int i) { return intervals[indices[i]].r; };

  std::vector<int> groups(n, 1);
  int i = 0;
  int max_r = get_r(0);
  while (i < n && get_l(i) <= max_r) {
    int j = indices[i];
    groups[j] = 2;
    max_r = std::max(get_r(i), max_r);
    ++i;
  }

  if (i >= n) {
    std::cout << -1 << '\n';
    return;
  }

  const char *separator = "";
  for (int group : groups) {
    std::cout << separator << group;
    separator = " ";
  }
  std::cout << '\n';
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
