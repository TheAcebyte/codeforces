#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, q;
  std::cin >> n >> q;

  i64 sum = 0;
  std::vector<int> a(n);
  for (int& x : a) {
    std::cin >> x;
    sum += x;
  }

  int changeId = 0;
  int changeValue = 0;
  std::vector<int> changes(n);
  while (q-- > 0) {
    int t;
    std::cin >> t;

    if (t == 1) {
      int i, x;
      std::cin >> i >> x;
      --i;

      int oldValue = changes[i] == changeId ? a[i] : changeValue;
      changes[i] = changeId;
      a[i] = x;

      sum += x - oldValue;
      std::cout << sum << '\n';
    } else {
      int x;
      std::cin >> x;

      ++changeId;
      changeValue = x;

      sum = (i64)n * x;
      std::cout << sum << '\n';
    }
  }
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  solve();

  return 0;
}
