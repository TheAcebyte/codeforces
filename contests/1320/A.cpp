#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

#define N 600000

using i64 = std::int64_t;

constexpr int offset = 400000;

void solve() {
  int n;
  std::cin >> n;

  std::vector<i64> beauties(N);
  for (int i = 0; i < n; ++i) {
    int b;
    std::cin >> b;

    int j = i - b + offset;
    beauties[j] += b;
  }

  i64 result = *std::max_element(beauties.begin(), beauties.end());
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
