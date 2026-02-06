#include <iostream>
#include <string>

void solve() {
  int n, r, b;
  std::cin >> n >> r >> b;

  std::string s(n, 'R');
  for (int i = 1; i <= b; ++i) {
    int j = i * n / (b + 1);
    s[j] = 'B';
  }

  std::cout << s << '\n';
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
