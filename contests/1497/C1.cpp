#include <iostream>

void solve() {
  int n, k;
  std::cin >> n >> k;

  int a, b, c;
  switch (n % 12) {
  case 0:
  case 3:
  case 6:
  case 9:
    a = b = c = n / 3;
    break;

  case 1:
  case 5:
  case 7:
  case 11:
    a = b = n / 2;
    c = 1;
    break;

  case 4:
  case 8:
    a = n / 2;
    b = c = n / 4;
    break;

  case 2:
  case 10:
    a = b = (n - 2) / 2;
    c = 2;
    break;
  }

  std::cout << a << ' ' << b << ' ' << c << '\n';
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
