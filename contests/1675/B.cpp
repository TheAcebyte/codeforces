#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int& x : a) {
    std::cin >> x;
  }

  int operations = 0;
  for (int i = n - 2; i >= 0; --i) {
    while (a[i] > 0 && a[i] >= a[i + 1]) {
      a[i] >>= 1;
      ++operations;
    }

    if (a[i] >= a[i + 1]) {
      std::cout << -1 << '\n';
      return;
    }
  }

  int result = operations;
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
