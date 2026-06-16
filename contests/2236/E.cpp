#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int& x : a) std::cin >> x;

  std::vector<std::vector<bool>> permutations(n + 1, std::vector<bool>(n + 1));
  std::vector<bool> seen(n + 1);
  for (int i = 0; i < n; ++i) {
    std::fill(seen.begin(), seen.end(), false);
    seen[a[i]] = true;
    permutations[a[i]][1] = true;
    int l = a[i];
    int r = a[i];
    for (int j = i + 1; j < n; ++j) {
      seen[a[j]] = true;
      while (l > 1 && seen[l - 1]) --l;
      while (r < n && seen[r + 1]) ++r;
      if (r - l + 1 == j - i + 1) {
        permutations[l][r - l + 1] = true;
      } 
    }
  }

  for (int k = n; k >= 1; --k) {
    for (int i = 1; i <= n - k; ++i) {
      if (permutations[i][k] && permutations[i + k][k]) {
        std::cout << k << '\n';
        return;
      }
    }
  }

  std::cout << 0 << '\n';
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
