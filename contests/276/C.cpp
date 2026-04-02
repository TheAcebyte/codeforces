#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, q;
  std::cin >> n >> q;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }
  std::sort(a.begin(), a.end());

  std::vector<int> d(n + 1);
  while (q-- > 0) {
    int l, r;
    std::cin >> l >> r;
    --l;
    --r;

    ++d[l];
    --d[r + 1];
  }

  std::vector<int> multipliers(n);
  int m = 0;
  for (int i = 0; i < n; ++i) {
    m += d[i];
    multipliers[i] = m;
  }
  std::sort(multipliers.begin(), multipliers.end());

  i64 result = 0;
  for (int i = 0; i < n; ++i) {
    result += (i64)multipliers[i] * a[i];
  }

  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
