#include <array>
#include <iostream>
#include <vector>

#define N 30

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  std::vector<std::array<int, N>> prefix(n + 1);
  prefix[0].fill(0);
  for (int i = 1; i <= n; ++i) {
    prefix[i] = prefix[i - 1];
    for (int j = 0; j < N; ++j) {
      int bit = (a[i] >> j) & 1;
      if (bit == 0) {
        ++prefix[i][j];
      }
    }
  }

  int q;
  std::cin >> q;

  const char* separator = "";
  while (q-- > 0) {
    int l, k;
    std::cin >> l >> k;

    int r = -1;
    int low = l;
    int high = n;
    while (low <= high) {
      int m = low + (high - low) / 2;
      int x = a[l];
      for (int j = 0; j < N; ++j) {
        if (prefix[m][j] > prefix[l - 1][j]) {
          x &= ~(1 << j);
        }
      }

      if (x >= k) {
        r = m;
        low = m + 1;
      } else {
        high = m - 1;
      }
    }

    std::cout << separator << r;
    separator = " ";
  }
  std::cout << '\n';
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
