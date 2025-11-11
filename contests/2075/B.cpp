#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  std::vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    b[i] = i;
  }

  auto cmp = [&a](int i, int j) { return a[i] > a[j]; };
  std::sort(b.begin(), b.end(), cmp);

  if (k == 1) {
    if (b[0] == 0 || b[0] == n - 1) {
      int result = a[b[0]] + a[b[1]];
      std::cout << result << '\n';
    } else {
      int result = a[b[0]] + std::max(a[0], a[n - 1]);
      std::cout << result << '\n';
    }
  } else {
    u64 result = 0;
    for (int i = 0; i <= k; ++i) {
      result += a[b[i]];
    }

    std::cout << result << '\n';
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
