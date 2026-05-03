#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> b(2 * n);
  for (int &x : b) {
    std::cin >> x;
  }
  std::sort(b.begin(), b.end());

  std::vector<i64> a(2 * n + 1);
  a[0] = b[2 * n - 1];
  int i = 1;
  int l = 0;
  int r = 2 * n - 2;
  i64 x = 0;
  while (l < r) {
    x += b[r] - b[l];
    a[i++] = b[l++];
    a[i++] = b[r--];
  }

  a[i++] = x + b[r] + b[2 * n - 1];
  a[i] = b[r];

  const char* separator = "";
  for (i64 x : a) {
    std::cout << separator << x;
    separator = " ";
  }
  std::cout << '\n';
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
