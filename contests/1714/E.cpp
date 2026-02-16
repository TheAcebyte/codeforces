#include <cstdlib>
#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  bool existing_zero = false;
  std::vector<int> a(n);
  for (int& x : a) {
    std::cin >> x;
    if (x % 10 == 5) {
      x += 5;
    }

    if (x % 10 == 0) {
      existing_zero = true;
    }
  }

  if (existing_zero) {
    for (int i = 0; i < n - 1; ++i) {
      if (a[i] != a[i + 1]) {
        std::cout << "NO\n";
        return;
      }
    }

    std::cout << "YES\n";
    return;
  }

  for (int& x : a) {
    while (x % 10 != 2) {
      x += x % 10;
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    int distance = a[i] - a[i + 1];
    if (distance % 20 != 0) {
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
