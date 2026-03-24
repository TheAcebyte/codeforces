#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }
  std::sort(a.begin(), a.end());

  int result = n;
  for (int i = 0; i < n - 2; ++i) {
    auto begin = a.begin() + i + 2;
    auto end = a.end();
    int j = std::lower_bound(begin, end, a[i] + a[i + 1]) - a.begin();
    result = std::min(i + n - j, result);
  }

  std::cout << result << '\n';
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
