#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int& x : a) {
    std::cin >> x;
  }
  std::sort(a.begin(), a.end());

  int l = 0;
  int r = 0;
  while (r < n) {
    int difference = a[r] - a[l];
    if (difference == k) {
      std::cout << "YES\n";
      return;
    } else if (difference < k) {
      ++r;
    } else {
      ++l;
    }
  }

  std::cout << "NO\n";
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
