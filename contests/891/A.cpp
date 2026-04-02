#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

constexpr int INF = std::numeric_limits<int>::max();

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int& x : a) { std::cin >> x; }

  int left_ones = 0;
  int result = INF;
  for (int i = 0; i < n; ++i) {
    int gcd = a[i];
    int j = i + 1;
    while (j < n && gcd > 1) {
      gcd = std::gcd(a[j], gcd);
      ++j;
    }

    if (gcd > 1) {
      continue;
    }

    int right_ones = std::count(a.begin() + j, a.end(), 1);
    result = std::min(
      n + j - i - 2 - left_ones - right_ones,
      result
    );

    left_ones += a[i] == 1;
  }

  if (result == INF) {
    std::cout << -1 << '\n';
    return;
  }

  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
