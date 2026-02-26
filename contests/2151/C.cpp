#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n;
  std::cin >> n;
  n *= 2;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  std::vector<i64> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    p[i] = a[i] + p[i - 1];
  }

  std::vector<i64> s(n + 1);
  s[1] = a[1];
  for (int i = 2; i <= n; ++i) {
    s[i] = a[i] + s[i - 2];
  }

  const char *separator = "";
  for (int k = 1; k <= n / 2; ++k) {
    i64 first_entrances = p[k];
    i64 last_exits = p[n] - p[n - k];
    i64 middle_entrances = s[n - k] - s[k];
    i64 middle_exits = s[n - k - 1] - s[k - 1];
    i64 stay_time =
        last_exits - first_entrances + middle_exits - middle_entrances;

    std::cout << separator << stay_time;
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
