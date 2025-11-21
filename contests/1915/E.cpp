#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (i & 1) {
      a[i] = -a[i];
    }
  }

  i64 sum = 0;
  std::set<i64> seen;
  for (int x : a) {
    sum += x;
    if (sum == 0 || seen.count(sum)) {
      std::cout << "YES\n";
      return;
    }
    seen.insert(sum);
  }

  std::cout << "NO\n";
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
