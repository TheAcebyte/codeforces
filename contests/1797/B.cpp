#include <iostream>
#include <vector>

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<std::vector<bool>> a(n, std::vector(n, false));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      bool x;
      std::cin >> x;
      a[i][j] = x;
    }
  }

  int changes = 0;
  for (int i = 0; i < n; ++i) {
    int mi = n - i - 1;
    for (int j = 0; j < n; ++j) {
      int mj = n - j - 1;
      if (a[i][j] != a[mi][mj]) {
        ++changes;
      }
    }
  }

  changes >>= 1;
  if (changes <= k && (n & 1 || (k - changes) % 2 == 0)) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
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
