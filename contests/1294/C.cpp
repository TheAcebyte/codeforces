#include <iostream>

void solve() {
  int n;
  std::cin >> n;

  int a = -1;
  int b = -1;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      n /= i;
      if (a == -1) {
        a = i;
      } else {
        b = i;
        break;
      }
    }
  }
  
  if (b == -1 || n == 1 || n == a || n == b) {
    std::cout << "NO\n";
    return;
  }

  int c = n;
  std::cout << "YES\n";
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
