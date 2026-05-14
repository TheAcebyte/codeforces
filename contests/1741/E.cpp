#include <iostream>
#include <set>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::set<int> s;
  std::vector<int> dp(n + 1);
  dp[n] = true;
  for (int i = n - 1; i >= 0; --i) {
    int x = a[i];
    if ((i + x < n && dp[i + x + 1]) || s.find(i) != s.end()) {
      dp[i] = true;
    }

    if (dp[i + 1]) {
      s.insert(i - x);
    }
  }

  std::cout << (dp[0] ? "YES" : "NO") << '\n';
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
