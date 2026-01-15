#include <algorithm>
#include <iostream>

void solve() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;

  int min = std::min(a, b);
  int max = std::max(a, b);
  if ((c > min && c < max && (d < min || d > max)) ||
      (d > min && d < max && (c < min || c > max))) {
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
