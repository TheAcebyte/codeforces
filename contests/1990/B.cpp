#include <iostream>
#include <vector>

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  --x;
  --y;

  std::vector<int> a(n, 1);
  int alt = -1;

  for (int i = y - 1; i >= 0; --i) {
    a[i] = alt;
    alt = -alt;
  }

  alt = -1;
  for (int i = x + 1; i < n; ++i) {
    a[i] = alt;
    alt = -alt;
  }

  const char *separator = "";
  for (int x : a) {
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
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  while (T-- > 0) {
    solve();
  }

  return 0;
}
