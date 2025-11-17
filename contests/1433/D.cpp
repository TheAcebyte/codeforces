#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  int x = 0;
  int y = -1;
  for (int i = 0; i < n; ++i) {
    if (i == x || i == y) {
      continue;
    }

    if (a[i] != a[x]) {
      y = i;
      break;
    }
  }

  if (y == -1) {
    std::cout << "NO\n";
    return;
  }

  std::cout << "YES\n";
  std::cout << x + 1 << ' ' << y + 1 << '\n';
  for (int i = 0; i < n; ++i) {
    if (i == x || i == y) {
      continue;
    }

    if (a[i] != a[x]) {
      std::cout << i + 1 << ' ' << x + 1 << '\n';
    } else {
      std::cout << i + 1 << ' ' << y + 1 << '\n';
    }
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
