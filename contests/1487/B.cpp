#include <iostream>

void solve() {
  int n, k;
  std::cin >> n >> k;
  --k;

  int result = 1 + (k + (n & 1) * k / (n >> 1)) % n;
  std::cout << result << '\n';
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
