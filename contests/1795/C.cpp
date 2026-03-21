#include <algorithm>
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

  std::vector<int> b(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> b[i];
  }

  std::vector<i64> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    p[i] = b[i] + p[i - 1];
  }

  std::vector<i64> full(n + 1);
  std::vector<i64> leftovers(n + 1);
  for (int i = 1; i <= n; ++i) {
    int j =
        std::upper_bound(p.begin() + i, p.end(), a[i] + p[i - 1]) - p.begin();
    ++full[i];
    if (j <= n) {
      --full[j];
      leftovers[j] += a[i] + p[i - 1] - p[j - 1];
    }
  }

  std::vector<i64> capacities(n + 1);
  i64 overlaps = 0;
  for (int i = 1; i <= n; ++i) {
    overlaps += full[i];
    capacities[i] = overlaps * b[i] + leftovers[i];
  }

  const char *separator = "";
  for (int i = 1; i <= n; ++i) {
    i64 capacity = capacities[i];
    std::cout << separator << capacity;
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
