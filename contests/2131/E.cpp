#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> b(n);
  for (int &x : b) {
    std::cin >> x;
  }

  if (a[n - 1] != b[n - 1]) {
    std::cout << "NO\n";
    return;
  }

  for (int i = 0; i < n - 1; ++i) {
    if (a[i] != b[i] && (a[i] ^ a[i + 1]) != b[i] &&
        (a[i] ^ b[i + 1]) != b[i]) {
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
