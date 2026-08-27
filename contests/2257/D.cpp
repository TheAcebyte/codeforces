#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

std::vector<i64> get_divisors(i64 x) {
  i64 d = 1;
  std::vector<i64> head, tail;
  for (; d * d < x; ++d) {
    if (x % d == 0) {
      head.push_back(d);
      tail.push_back(x / d);
    }
  }

  if (d * d == x) {
    head.push_back(d);
  }

  head.reserve(head.size() + tail.size());
  head.insert(head.end(), tail.rbegin(), tail.rend());
  return head;
}

void solve() {
  i64 s;
  int q;
  std::cin >> s >> q;

  auto d = get_divisors(s);
  int m = d.size();
  std::vector<i64> p(m);
  p[0] = s;
  for (int i = 1; i < m; ++i) {
    p[i] = p[i - 1] + s / d[i] * (d[i] - d[i - 1]);
  }

  auto range_sum = [&](int l, int r) -> i64 {
    assert(l >= 0 && r < m);
    i64 sum = p[r];
    if (l > 0) sum -= p[l - 1];
    return sum;
  };

  while (q-- > 0) {
    i64 x, y;
    std::cin >> x >> y;

    i64 k = d.rend() - 1 - std::upper_bound(
        d.rbegin(), d.rend(), y, std::greater<i64>()
    );

    int i = m - k - 1;
    int j = std::upper_bound(d.begin(), d.end(), x) - d.begin();

    i64 cells = 0;
    if (i > j) {
      cells = x * y;
    } else {
      if (i > 0) cells += d[i - 1] * y;
      if (i < j) cells += range_sum(i, j - 1);
      if (j < m) cells += s / d[j] * (x - d[j - 1]);
    }

    std::cout << cells << '\n';
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
