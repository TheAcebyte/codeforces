#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#define INF 1000000

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  int g = a[0];
  int max = a[0];
  for (int x : a) {
    g = std::gcd(x, g);
    max = std::max(x, max);
  }

  int occurences = 0;
  for (int x : a) {
    occurences += x == g;
  }

  if (occurences > 0) {
    int operations = n - occurences;
    std::cout << operations << '\n';
    return;
  }

  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(max + 1));
  std::fill(dp[n].begin(), dp[n].end(), INF);
  dp[n][g] = 0;

  for (int i = n - 1; i >= 0; --i) {
    for (int x = g; x <= max; ++x) {
      int y = std::gcd(x, a[i]);
      dp[i][x] = std::min(dp[i + 1][x], 1 + dp[i + 1][y]);
    }
  }

  int operations = INF;
  for (int x : a) {
    operations = std::min(dp[0][x] + n - 1, operations);
  }

  std::cout << operations << '\n';
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
