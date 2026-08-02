#include <algorithm>
#include <iostream>
#include <vector>

void setmax(int& x, int y) { if (y > x) x = y; }

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int& x : a) std::cin >> x;

  std::vector<int> p(n);
  p[0] = a[0];
  for (int i = 1; i < n; ++i) {
    p[i] = std::max(a[i] + i, p[i - 1]);
  }

  std::vector<int> s(n);
  s[n - 1] = a[n - 1] - n + 1;
  for (int i = n - 2; i >= 0; --i) {
    s[i] = std::max(a[i] - i, s[i + 1]);
  }

  int max_score = 0;
  for (int i = 1; i < n - 1; ++i) {
    int score = a[i] + p[i - 1] + s[i + 1];
    setmax(max_score, score);
  }

  std::cout << max_score << '\n';
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
