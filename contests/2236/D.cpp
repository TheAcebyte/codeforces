#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int& x : a) std::cin >> x;
  std::sort(a.begin(), a.end());

  for (int i = n - 1; i >= 0; --i) {
    int j = i;
    while (i > 0 && a[i - 1] == a[i]) {
      --i;
    }

    int length = j - i + 1;
    if (length % 2 == 0 || (i > 0 && a[i] - a[i - 1] <= k)) {
      std::cout << "YES\n";
      return;
    }
  }

  std::cout << "NO\n";
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
