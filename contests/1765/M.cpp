#include <cstdint>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

void solve() {
  int n, k, q;
  std::cin >> n >> k >> q;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  u64 result = 0;
  int l = 0;
  for (int r = 0; r < n; ++r) {
    if (a[r] > q) {
      l = r + 1;
    } else if (r - l + 1 >= k) {
      result += r - l - k + 2;
    }
  }

  std::cout << result << '\n';
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
