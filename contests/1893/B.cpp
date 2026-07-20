#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n), b(m);
  for (int& x : a) std::cin >> x;
  for (int& x : b) std::cin >> x;
  std::sort(b.rbegin(), b.rend());

  std::vector<int> c(n + m);
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < n && j < m) {
    if (b[j] >= a[i]) {
      c[k++] = b[j++];
    } else {
      c[k++] = a[i++];
    }
  }

  while (i < n) c[k++] = a[i++];
  while (j < m) c[k++] = b[j++];

  for (int k = 0; k < n + m; ++k) {
    std::cout << c[k] << " \n"[k == n + m - 1];
  }
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
