#include <iostream>

void solve() {
  int n;
  std::cin >> n;

  int k = n / 2;
  if (n % 2 == 0) {
    int result = (k + 1) * (k + 1);
    std::cout << result << '\n';
  } else {
    int k = n / 2;
    int result = 2 * (k + 1) * (k + 2);
    std::cout << result << '\n';
  }
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  solve();

  return 0;
}
