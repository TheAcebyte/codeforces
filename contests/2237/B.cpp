#include <iostream>
#include <utility>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) std::cin >> x;

  std::vector<int> b(n);
  for (int &x : b) std::cin >> x;

  int swaps = 0;
  for (int i = 0; i < n; ++i) {
    int j = i;
    for (; j < n && a[j] > b[i]; ++j);
    if (j == n) {
      std::cout << -1 << '\n';
      return;
    }

    swaps += j - i;
    for (; j > i; --j) std::swap(a[j - 1], a[j]); 
  }

  std::cout << swaps << '\n';
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
