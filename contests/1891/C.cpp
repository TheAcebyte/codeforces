#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }
  std::sort(a.begin(), a.end());

  i64 moves = 0;
  int c = 0;
  int l = 0;
  int r = n - 1;
  while (l < r) {
    if (c + a[l] < a[r]) {
      c += a[l];
      moves += a[l];
      ++l;
    } else {
      a[l] -= a[r] - c;
      moves += a[r] - c + 1;
      c = 0;
      --r;
    }
  }

  if (l == r) {
    int h = a[l];
    if (h <= 1) {
      moves += h;
    } else {
      moves += 1 + (h - c + 1) / 2;
    }
  }

  i64 result = moves;
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
