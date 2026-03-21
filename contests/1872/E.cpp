#include <iostream>
#include <string>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  std::vector<int> prefix_xor(n + 1);
  for (int i = 1; i <= n; ++i) {
    prefix_xor[i] = a[i] ^ prefix_xor[i - 1];
  }

  std::string s;
  int q;
  std::cin >> s >> q;

  int xor_zeros = 0;
  int xor_ones = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i - 1] == '0') {
      xor_zeros ^= a[i];
    } else {
      xor_ones ^= a[i];
    }
  }

  const char* separator = "";
  while (q-- > 0) {
    int t;
    std::cin >> t;

    if (t == 1) {
      int l, r;
      std::cin >> l >> r;

      int range_xor = prefix_xor[r] ^ prefix_xor[l - 1];
      xor_zeros ^= range_xor;
      xor_ones ^= range_xor;
    } else {
      int g;
      std::cin >> g;

      if (g == 0) {
        std::cout << separator << xor_zeros;
      } else {
        std::cout << separator << xor_ones;
      }

      separator = " ";
    }
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
