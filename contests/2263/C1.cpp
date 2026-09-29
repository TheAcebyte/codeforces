#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int& x : a) std::cin >> x;

  std::vector<int> excluded(n);
  for (int i = 0; i < n; ++i) {
    int opening = a[i] * (i + 1);
    int closing = opening + i + 1;
    if (opening < n) ++excluded[opening];
    if (closing < n) --excluded[closing];
  }

  std::vector<int> set;
  int intersections = 0;
  for (int x = 0; x < n; ++x) {
    intersections += excluded[x];
    if (intersections == 0) {
      set.push_back(x);
    }
  }

  int m = set.size();
  std::cout << m << '\n';
  for (int i = 0; i < m; ++i) {
    std::cout << set[i] << " \n"[i == m - 1];
  }
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
