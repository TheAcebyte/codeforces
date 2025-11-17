#include <iostream>

void solve() {
  int a, b, c;
  std::cin >> a >> b >> c;

  int sum = a + b + c;
  int min = std::min(a, std::min(b, c));

  if (sum % 9 == 0 && min >= sum / 9) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
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
