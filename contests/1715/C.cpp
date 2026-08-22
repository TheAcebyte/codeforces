#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n);
  i64 awesomeness = (i64)n * (n + 1) / 2;
  auto update = [&](i64 i, int x) {
    assert(i >= 0 && i < n);

    if (i > 0) {
      awesomeness -= (a[i - 1] != a[i]) * i * (n - i);
      awesomeness += (a[i - 1] != x) * i * (n - i);
    }

    if (i < n - 1) {
      awesomeness -= (a[i + 1] != a[i]) * (i + 1) * (n - i - 1);
      awesomeness += (a[i + 1] != x) * (i + 1) * (n - i - 1);
    }

    a[i] = x;
  };

  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    update(i, x);
  }

  while (m-- > 0) {
    int i, x;
    std::cin >> i >> x;
    update(i - 1, x);
    std::cout << awesomeness << '\n';
  }
}

int main() {
#ifndef ONLINE_JUDGE
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
