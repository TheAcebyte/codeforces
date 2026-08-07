#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

constexpr int M = 1e6;
i64 count[M + 1];

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int& x : a) {
    std::cin >> x;
    ++count[x];
  }

  i64 result = 0;
  for (int x : a) {
    result += (count[x] - 1) * (count[x] - 2);
    for (int d = 2; x * d * d <= M; ++d) {
      result += count[x * d] * count[x * d * d];
    }
  }

  for (int x : a) --count[x];
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
