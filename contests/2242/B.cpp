#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int& x : a) std::cin >> x;

  int i = 1;
  int ones = a[0] == 1;
  while (i < n - 2 && ones < (i + 1) / 2) {
    ones += a[i] == 1;
    ++i;
  }

  if (ones < (i + 1) / 2) {
    std::cout << "NO" << '\n';
    return;
  }

  if (i < n - 2 && i % 2 == 1 && a[i] == 3) {
    ++i;
  }

  int j = i + 1;
  int threes = a[i] == 3;
  while (j < n - 1 && threes > (j - i) / 2) {
    threes += a[j] == 3;
    ++j;
  }

  if (threes > (j - i) / 2) {
    std::cout << "NO" << '\n';
    return;
  }

  std::cout << "YES" << '\n';
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
