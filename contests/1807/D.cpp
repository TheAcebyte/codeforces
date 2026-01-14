#include <cstdint>
#include <iostream>
#include <vector>

using u8 = std::uint8_t;

void solve() {
  int n, q;
  std::cin >> n >> q;

  std::vector<int> a(n + 2);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  std::vector<u8> prefix(n + 2);
  for (int i = 1; i <= n; ++i) {
    prefix[i] = (a[i] & 1) ^ prefix[i - 1];
  }

  std::vector<u8> suffix(n + 2);
  for (int i = n; i >= 1; --i) {
    suffix[i] = (a[i] & 1) ^ suffix[i + 1];
  }

  for (int i = 0; i < q; ++i) {
    int l, r, k;
    std::cin >> l >> r >> k;

    if (prefix[l - 1] ^ suffix[r + 1] ^ (((r - l + 1) & 1) & (k & 1))) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
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
