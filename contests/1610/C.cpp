#include <cassert>
#include <iostream>
#include <vector>

struct person {
  int a, b;
};

void solve() {
  int n;
  std::cin >> n;

  std::vector<person> p(n);
  for (auto& x : p) { std::cin >> x.a >> x.b; }

  auto is_feasible = [&](int m) {
    assert(m >= 0 && m <= n);
    int a = m - 1;
    int b = 0;
    for (int i = 0; i < n && a >= 0; ++i) {
      if (p[i].a >= a && p[i].b >= b) {
        --a;
        ++b;
      }
    }

    return a < 0;
  };

  int l = 1;
  int r = n;
  int result = 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (is_feasible(m)) {
      result = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  std::cout << result << '\n';
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
