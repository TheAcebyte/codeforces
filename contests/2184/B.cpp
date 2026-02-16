#include <iostream>

void solve() {
  int s, k, m;
  std::cin >> s >> k >> m;

  int q = m / k;
  int r = m % k;
  if (s > k) {
    if (q % 2 == 0) {
      int result = s - r;
      std::cout << result << '\n';
    } else {
      int result = k - r;
      std::cout << result << '\n';
    }
  } else if (r > s) {
    int result = 0;
    std::cout << result << '\n';
  } else {
    int result = s - r;
    std::cout << result << '\n';
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
