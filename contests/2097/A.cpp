#include <iostream>
#include <map>

void solve() {
  int n;
  std::cin >> n;

  std::map<int, int> count;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ++count[x];
  }

  for (auto [x, c] : count) {
    if (c >= 4) {
      std::cout << "YES\n";
      return;
    } else if (c >= 2) {
      count[x + 1] *= 2;
    }
  }

  std::cout << "NO\n";
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
