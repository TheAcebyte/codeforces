#include <cstdint>
#include <iostream>
#include <string>

using u64 = std::uint64_t;

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  auto count_swaps = [&](char middle) -> u64 {
    u64 swaps = 0;
    int leftBlock = 0;
    int rightBlock = 0;
    int left = 0;
    int right = n - 1;
    while (left <= right) {
      if (s[left] == middle) {
        ++leftBlock;
        ++left;
      } else if (s[right] == middle) {
        ++rightBlock;
        --right;
      } else if (leftBlock <= rightBlock) {
        swaps += leftBlock;
        ++left;
      } else {
        swaps += rightBlock;
        --right;
      }
    }

    return swaps;
  };

  u64 result = std::min(count_swaps('a'), count_swaps('b'));
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
