#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

constexpr int inf = 1e9;

template<typename T>
void setmin(T& x, const T& y) {
  if (y < x) x = y;
}

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n);
  for (int& x : a) std::cin >> x;
  std::sort(a.begin(), a.end());

  std::vector<int> divisors(m + 1);
  int d = 0;
  auto increase = [&](int x) {
    if (x <= 0 || x > m) return;
    if (divisors[x] == 0) ++d;
    ++divisors[x];
  };

  auto decrease = [&](int x) {
    if (x <= 0 || x > m) return;
    --divisors[x];
    if (divisors[x] == 0) --d;
  };

  int r = 0;
  int min_difference = inf;
  for (int l = 0; l < n; ++l) {
    while (r < n && d < m) {
      for (int x = 1; x * x <= a[r]; ++x) {
        if (a[r] % x > 0) continue;
        increase(x);
        increase(a[r] / x);
      }

      ++r;
    }

    if (d < m) break;
    setmin(min_difference, a[r - 1] - a[l]);

    for (int x = 1; x * x <= a[l]; ++x) {
      if (a[l] % x > 0) continue;
      decrease(x);
      decrease(a[l] / x);
    }
  }

  int answer = min_difference == inf ? -1 : min_difference;
  std::cout << answer << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t-- > 0) {
    solve();
  }

  return 0;
}
