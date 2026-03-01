#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> ternary;
  int deals = 0;
  i64 total_cost = 0;

  i64 p = 1;
  int i = 0;
  while (n > 0) {
    i64 cost = 3 * p + i * p / 3;
    int r = n % 3;

    ternary.push_back(r);
    deals += r;
    total_cost += r * cost;

    n /= 3;
    p *= 3;
    ++i;
  }

  if (deals > k) {
    std::cout << -1 << '\n';
    return;
  }

  int m = ternary.size();
  p /= 9;

  for (int i = m - 1; i > 0; --i) {
    int d = std::min((k - deals) / 2, ternary[i]);

    ternary[i - 1] += 3 * d;
    deals += 2 * d;
    total_cost -= d * p;

    p /= 3;
  }

  i64 result = total_cost;
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
