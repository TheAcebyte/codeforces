#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  for (int i = 0; i < n - 1; ++i) {
    if (a[i] > a[i + 1]) {
      std::cout << "NO\n";
      return;
    }

    a[i + 1] -= a[i];
    a[i] = 0;
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
