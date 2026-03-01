#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <utility>
#include <vector>

using i64 = std::int64_t;

constexpr int INF = std::numeric_limits<int>::max();

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> b(n);
  for (int &x : b) {
    std::cin >> x;
  }

  i64 v = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] < b[i]) {
      std::swap(a[i], b[i]);
    }

    v += a[i] - b[i];
  }

  std::vector<int> indices(n);
  std::iota(indices.begin(), indices.end(), 0);
  auto cmp = [&](int i, int j) { return a[i] > a[j]; };
  std::sort(indices.begin(), indices.end(), cmp);

  int dv = INF;
  for (int x = 0; x < n - 1; ++x) {
    int i = indices[x];
    int j = indices[x + 1];
    if (a[j] >= b[i]) {
      dv = 0;
      break;
    } else {
      dv = std::min(2 * (b[i] - a[j]), dv);
    }
  }

  i64 result = v + dv;
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
