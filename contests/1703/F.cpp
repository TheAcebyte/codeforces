#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  std::vector<int> prefix(n + 1);
  for (int i = 1; i <= n; ++i) {
    prefix[i] = prefix[i - 1];
    if (a[i] < i) {
      ++prefix[i];
    }
  }

  i64 result = 0;
  for (int i = n; i >= 1; --i) {
    if (a[i] == 0 || a[i] >= i) {
      continue;
    }

    result += prefix[a[i] - 1];
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
