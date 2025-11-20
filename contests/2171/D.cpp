#include <cstdint>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> p(n);
  for (int &x : p) {
    std::cin >> x;
  }

  u64 a = 0;
  u64 b = 0;
  for (int i = 1; i < n; ++i) {
    a += i;
    b += p[n - i];

    if (a == b) {
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
