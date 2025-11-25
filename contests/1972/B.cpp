#include <iostream>

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  int count = 0;
  for (char c : s) {
    if (c == 'U') {
      ++count;
    }
  }


  if (count % 2 == 0) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
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
