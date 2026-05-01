#include <algorithm>
#include <cstdint>
#include <iostream>

using i64 = std::int64_t;

constexpr i64 inf = 1e10;

void solve() {
  int n;
  std::cin >> n;

  i64 score = 0;
  i64 diff_parity_swap_cost = 0;
  i64 even_max = -inf;
  i64 odd_max = -inf;
  for (int i = 0; i < n; ++i) {
    i64 x;
    std::cin >> x;
    if (i % 2 == 0) {
      score += x;
      diff_parity_swap_cost = std::max(odd_max + i - 2 * x, diff_parity_swap_cost);
      even_max = std::max(-i - 2 * x, even_max);
    } else {
      score -= x;
      diff_parity_swap_cost = std::max(even_max + i + 2 * x, diff_parity_swap_cost);
      odd_max = std::max(-i + 2 * x, odd_max);
    }
  }

  i64 no_swap_score = score;
  i64 same_parity_swap_score = score + n - 1 - (n - 1) % 2;
  i64 diff_parity_swap_score = score + diff_parity_swap_cost;
  i64 optimal_score =
      std::max({no_swap_score, same_parity_swap_score, diff_parity_swap_score});

  std::cout << optimal_score << '\n';
}

int main() {
#ifdef DEBUG
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
