#include <algorithm>
#include <iostream>
#include <vector>

int lsb(int n) {
  return n & (-n);
}

void solve() {
  int n;
  std::cin >> n;

  int s = 0;
  std::vector<int> a(n);
  for (int& x : a) {
    std::cin >> x;
    s += x;
  }

  if (s % 2 == 1) {
    std::cout << 0 << '\n';
    return;
  }

  int half_s = s / 2;
  std::vector<bool> dp(half_s + 1);
  dp[0] = true;
  for (int i = 0; i < n; ++i) {
    for (int x = half_s - a[i]; x >= 0; --x) {
      dp[x + a[i]] = dp[x + a[i]] || dp[x];
    }
  }

  if (!dp[half_s]) {
    std::cout << 0 << '\n';
    return;
  }

  auto cmp_lsb = [](int x, int y) { return lsb(x) < lsb(y); };
  auto min_it = std::min_element(a.begin(), a.end(), cmp_lsb);
  int i = min_it - a.begin() + 1;
  std::cout << 1 << '\n' << i << '\n';
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
