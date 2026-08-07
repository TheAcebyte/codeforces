#include <algorithm>
#include <iostream>
#include <vector>

void setmax(int& x, int y) {
  if (y > x) x = y;
}

void solve() {
  int n;
  std::cin >> n;
  n *= 2;

  int j = -1;
  int k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (a[i] > 0) continue;
    if (j == -1) j = i;
    else k = i;
  }

  int mex = 1;
  auto test_palindrome = [&](int l, int r) {
    std::vector<int> seen(n);
    while (l >= 0 && r < n && a[l] == a[r]) {
      int x = a[l];
      seen[x] = true;
      --l;
      ++r;
    }

    int m = std::find(seen.begin(), seen.end(), false) - seen.begin();
    setmax(mex, m);
  };

  int l = (j + k) / 2;
  int r = (j + k + 1) / 2;
  test_palindrome(j, j);
  test_palindrome(k, k);
  test_palindrome(l, r);

  std::cout << mex << '\n';
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
