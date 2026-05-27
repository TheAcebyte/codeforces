#include <cstdlib>
#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) { std::cin >> a[i]; }

  std::vector<int> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] + (std::abs(a[i]) == 2);
  }

  int l_max = -1;
  int r_max = -1;
  auto test_answer = [&](int l, int r) {
    if (l_max == -1 || r_max == -1) {
      l_max = l;
      r_max = r;
      return;
    }

    int count = p[r] - p[l - 1];
    int max_count = p[r_max] - p[l_max - 1];
    if (count > max_count) {
      l_max = l;
      r_max = r;
    }
  };

  auto test_subarray = [&](int l, int r) {
    if (l > r) {
      return;
    }

    bool negative = false;
    int j = -1;
    int k;
    for (int i = l; i <= r; ++i) {
      if (a[i] > 0) {
        continue;
      }

      negative = !negative;
      if (j == -1) j = i;
      k = i;
    }

    if (!negative) {
      test_answer(l, r);
    } else {
      test_answer(l, k - 1);
      test_answer(j + 1, r);
    }
  };

  int i = 1;
  while (i <= n) {
    while (i <= n && a[i] == 0) ++i;
    int j = i;
    while (i <= n && a[i] != 0) ++i;
    test_subarray(j, i - 1);
  }

  if (l_max == -1 && r_max == -1) {
    int x = 0;
    int y = n;
    std::cout << x << ' ' << y << '\n';
  } else {
    int x = l_max - 1;
    int y = n - r_max;
    std::cout << x << ' ' << y << '\n';
  }
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
