#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

std::array<std::pair<int, int>, 4> get_rotated_pairs(int i, int j, int n) {
  return {{
      {i, j},
      {j, n - i - 1},
      {n - i - 1, n - j - 1},
      {n - j - 1, i},
  }};
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::string> a(n);
  for (auto& row : a) {
    std::cin >> row;
  }

  int result = 0;
  int ni = (n + 1) / 2;
  int nj = n / 2;
  for (int i = 0; i < ni; ++i) {
    for (int j = 0; j < nj; ++j) {
      auto rotated_pairs = get_rotated_pairs(i, j, n);
      int zeros = 0;
      int ones = 0;
      for (auto [ri, rj] : rotated_pairs) {
        if (a[ri][rj] == '0') {
          ++zeros;
        } else {
          ++ones;
        }
      }

      result += std::min(zeros, ones);
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
