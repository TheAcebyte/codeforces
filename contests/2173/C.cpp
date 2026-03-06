#include <iostream>
#include <map>
#include <vector>

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::map<int, bool> values;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    values[x] = false;
  }

  std::vector<int> b;
  for (auto [x, handled] : values) {
    if (handled) {
      continue;
    }

    if (k / x > n) {
      std::cout << -1 << '\n';
      return;
    }

    for (int y = x; y <= k; y += x) {
      if (values.find(y) == values.end()) {
        std::cout << -1 << '\n';
        return;
      }

      values[y] = true;
    }

    b.push_back(x);
  }

  int m = b.size();
  std::cout << m << '\n';

  const char *separator = "";
  for (int x : b) {
    std::cout << separator << x;
    separator = " ";
  }
  std::cout << '\n';
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
