#include <algorithm>
#include <iostream>
#include <vector>

constexpr int INF = 1e9;

struct interval {
  int l;
  int r;
};

void solve() {
  int n;
  std::cin >> n;

  std::vector<interval> intervals(n);
  for (auto &interval : intervals) {
    std::cin >> interval.l >> interval.r;
  }

  int result;
  int low = 0;
  int high = INF;
  while (low <= high) {
    int k = low + (high - low) / 2;
    int l = 0;
    int r = 0;

    int valid = true;
    for (auto interval : intervals) {
      if (r + k < interval.l || l - k > interval.r) {
        valid = false;
        break;
      }

      l = std::max(l - k, interval.l);
      r = std::min(r + k, interval.r);
    }

    if (valid) {
      result = k;
      high = k - 1;
    } else {
      low = k + 1;
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

  int T;
  std::cin >> T;
  while (T-- > 0) {
    solve();
  }

  return 0;
}
