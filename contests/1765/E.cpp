#include <iostream>

void solve() {
  int n, a, b;
  std::cin >> n >> a >> b;

  if (a <= b) {
    int result = (n + a - 1) / a;
    std::cout << result << '\n';
  } else {
    std::cout << 1 << '\n';
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
