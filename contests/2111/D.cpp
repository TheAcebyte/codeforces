#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(m);
  for (int &x : a) {
    std::cin >> x;
  }
  std::sort(a.begin(), a.end());

  for (int i = 0; i < n / 2; ++i) {
    const char *separator = "";
    for (int j = 0; j < 3; ++j) {
      std::cout << separator << a[i] << ' ' << a[m - i - 1];
      separator = " ";
    }
    std::cout << '\n';

    separator = "";
    for (int j = 0; j < 3; ++j) {
      std::cout << separator << a[m - i - 1] << ' ' << a[i];
      separator = " ";
    }
    std::cout << '\n';
  }

  if (n & 1) {
    const char *separator = "";
    for (int j = 0; j < 3; ++j) {
      std::cout << separator << a[n / 2] << ' ' << a[m - n / 2 - 1];
      separator = " ";
    }
    std::cout << '\n';
  }
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
