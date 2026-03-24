#include <algorithm>
#include <iostream>
#include <vector>

int log2(int n) {
  int i = -1;
  while (n > 0) {
    n >>= 1;
    ++i;
  }

  return i;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  int max_t = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i - 1]) {
      int t = 1 + log2(a[i - 1] - a[i]);
      a[i] = a[i - 1];
      max_t = std::max(t, max_t);
    }
  }

  int result = max_t;
  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
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
