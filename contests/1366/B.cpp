#include <algorithm>
#include <iostream>

void solve() {
  int n, x, m;
  std::cin >> n >> x >> m;
  --x;

  int left = x;
  int right = x;
  for (int i = 0; i < m; ++i) {
    int l, r;
    std::cin >> l >> r;
    --l;
    --r;

    if ((left >= l && left <= r) || (right <= r && right >= l) ||
        (left >= l && right <= r)) {
      left = std::min(l, left);
      right = std::max(r, right);
    }
  }

  int result = right - left + 1;
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
