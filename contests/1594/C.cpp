#include <iostream>
#include <string>

void solve() {
  int n;
  char c;
  std::string s;
  std::cin >> n >> c >> s;
  s = " " + s;

  bool matching = true;
  for (int i = 1; i <= n; ++i) {
    if (s[i] != c) {
      matching = false;
      break;
    }
  }

  if (matching) {
    std::cout << 0 << '\n';
    return;
  }

  for (int i = 1; i <= n; ++i) {
    bool divisible = false;
    for (int j = i; j <= n; j += i) {
      if (s[j] != c) {
        divisible = true;
        break;
      }
    }

    if (!divisible) {
      std::cout << 1 << '\n';
      std::cout << i << '\n';
      return;
    }
  }

  std::cout << 2 << '\n';
  std::cout << n - 1 << ' ' << n << '\n';
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
