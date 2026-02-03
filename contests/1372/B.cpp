#include <iostream>

void solve() {
  int n;
  std::cin >> n;

  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      int a = n / i;
      int b = n / i * (i - 1);
      std::cout << a << ' ' << b << '\n';
      return;
    }
  }

  int a = 1;
  int b = n - 1;
  std::cout << a << ' ' << b << '\n';
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
