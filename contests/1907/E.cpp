#include <cstdint>
#include <iostream>

using i64 = std::int64_t;

int digit_combinations[10];

void precompute_digit_combinations(int i = 0, int x = 0) {
  if (x > 9) {
    return;
  }

  if (i >= 3) {
    ++digit_combinations[x];
    return;
  }

  for (int y = 0; y <= 9; ++y) {
    precompute_digit_combinations(i + 1, x + y);
  }
}

void solve() {
  int n;
  std::cin >> n;

  i64 combinations = 1;
  while (n > 0) {
    int d = n % 10;
    combinations *= digit_combinations[d];
    n /= 10;
  }

  std::cout << combinations << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  precompute_digit_combinations();

  int t;
  std::cin >> t;
  while (t-- > 0) {
    solve();
  }

  return 0;
}
