#include <iostream>
#include <string>

void solve() {
  int n;
  std::string a, b;
  std::cin >> n >> a >> b;

  int zeros = 0;
  int ones = 0;
  int i = 0;
  while (i < n) {
    while (i < n && a[i] != b[i]) {
      if (a[i] == '0') {
        ++zeros;
      } else {
        ++ones;
      }

      ++i;
    }

    if (zeros != ones) {
      std::cout << "NO\n";
      return;
    }

    while (i < n && a[i] == b[i]) {
      if (a[i] == '0') {
        ++zeros;
      } else {
        ++ones;
      }

      ++i;
    }

    if (i < n && zeros != ones) {
      std::cout << "NO\n";
      return;
    }
  }

  std::cout << "YES\n";
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
