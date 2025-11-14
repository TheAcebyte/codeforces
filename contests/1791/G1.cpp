#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n, c;
  std::cin >> n >> c;

  std::vector<int> cost(n);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    cost[i] = x + i + 1;
  }
  std::sort(cost.begin(), cost.end());

  int i = 0;
  while (i < n && c >= cost[i]) {
    c -= cost[i];
    ++i;
  }

  int result = i;
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
