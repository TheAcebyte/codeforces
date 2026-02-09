#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n);
  a[0] = 1;
  for (int i = 1; i < n; ++i) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());

  std::vector<int> b(n);
  for (int &x : b) {
    std::cin >> x;
  }
  std::sort(b.begin(), b.end());

  int removals = 0;
  int i = 0;
  int j = 0;
  while (j < n) {
    if (a[i] < b[j]) {
      ++i;
      ++j;
    } else {
      ++removals;
      ++j;
    }
  }

  int result = removals;
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
