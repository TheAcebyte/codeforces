#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }
  std::sort(a.begin(), a.end());

  int maxLength = 1;
  int length = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] - a[i - 1] > k) {
      maxLength = std::max(length, maxLength);
      length = 0;
    }

    ++length;
  }
  maxLength = std::max(length, maxLength);

  int result = n - maxLength;
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
