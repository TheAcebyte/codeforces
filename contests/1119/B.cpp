#include <algorithm>
#include <iostream>
#include <vector>

struct iv {
  int index;
  int value;

  bool operator<(const iv &other) const { return value < other.value; }
};

void solve() {
  int n, h;
  std::cin >> n >> h;

  std::vector<iv> a(n);
  for (int i = 0; i < n; ++i) {
    a[i].index = i;
    std::cin >> a[i].value;
  }
  std::sort(a.rbegin(), a.rend());

  int l = 0;
  int r = n - 1;
  int result = -1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    int k = m + 1;

    int height = h;
    int i = 0;
    while (i < n) {
      while (i < n && a[i].index > m) {
        ++i;
      }

      if (i >= n || a[i].value > height) {
        break;
      }

      height -= a[i].value;
      ++i;

      while (i < n && a[i].index > m) {
        ++i;
      }

      if (i < n) {
        ++i;
      }
    }

    if (i >= n) {
      result = k;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  solve();

  return 0;
}
