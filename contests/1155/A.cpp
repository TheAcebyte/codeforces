#include <iostream>
#include <string>

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  for (int i = 0; i < n - 1; ++i) {
    if (s[i] > s[i + 1]) {
      std::cout << "YES\n";
      std::cout << i + 1 << ' ' << i + 2 << '\n';
      return;
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
  solve();

  return 0;
}
