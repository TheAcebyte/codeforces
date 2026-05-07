#include <cassert>
#include <iostream>
#include <vector>

struct segment {
  int l;
  int r;
};

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<segment> segments(m);
  for (auto& segment : segments) { std::cin >> segment.l >> segment.r; }

  int q;
  std::cin >> q;
  std::vector<int> changes(q);
  for (int& x : changes) { std::cin >> x; }

  auto check_majority_existence = [&](int k) {
    assert(k < q);
    std::vector<bool> a(n + 1);
    for (int i = 0; i <= k; ++i) {
      int x = changes[i];
      a[x] = true;
    }

    std::vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
      p[i] = a[i] + p[i - 1];
    }

    for (auto [l, r] : segments) {
      int length = r - l + 1;
      int ones = p[r] - p[l - 1];
      if (ones > length / 2) {
        return true;
      }
    }

    return false;
  };

  int l = 0;
  int r = q - 1;
  int result = -1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (check_majority_existence(m)) {
      result = m + 1;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
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
