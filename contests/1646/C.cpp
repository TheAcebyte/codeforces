#include <algorithm>
#include <cstdint>
#include <iostream>

using i64 = std::int64_t;

constexpr i64 N = 1000000000000;

int popcount(i64 n) {
  int count = 0;
  while (n > 0) {
    count += n & 1;
    n >>= 1;
  }

  return count;
}

int find_smallest_combination(int i, i64 f, i64 x) {
  if (f > N) {
    return popcount(x);
  }

  ++i;
  int result = find_smallest_combination(i, f * i, x);
  if (f <= x) {
    result = std::min(
      1 + find_smallest_combination(i, f * i, x - f),
      result
    );
  }

  return result;
}

void solve() {
  i64 n;
  std::cin >> n;

  int result = find_smallest_combination(0, 1, n);
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
