#include <iostream>
#include <vector>

template<typename T>
void setmin(T& x, const T& y) { if (y < x) x = y; }

void solve() {
  int n, l, k;
  std::cin >> n >> l >> k;

  std::vector<int> d(n), a(n);
  for (int& x : d) std::cin >> x;
  for (int& x : a) std::cin >> x;

  std::vector<std::vector<int>> dp(n, std::vector<int>(k + 1));
  for (int j = 0; j < n; ++j) {
    for (int x = 0; x <= k; ++x) {
      dp[j][x] = (l - d[j]) * a[j];
    }
  }

  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < i; ++j) {
      for (int x = k; x >= 0; --x) {
        dp[j][x] = dp[i][x] + (d[i] - d[j]) * a[j];
        if (x > 0) {
          setmin(dp[j][x], dp[j][x - 1]);
        }
      }
    }
  }

  int min_cost = dp[0][k];
  std::cout << min_cost << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
