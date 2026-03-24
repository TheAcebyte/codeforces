#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n, d, k;
  std::cin >> n >> d >> k;

  std::vector<int> openings(n + 2);
  std::vector<int> closings(n + 2);
  for (int i = 0; i < k; ++i) {
    int l, r;
    std::cin >> l >> r;

    ++openings[l];
    ++closings[r + 1];
  }

  int active_overlaps = 0;
  for (int i = 1; i <= d; ++i) {
    active_overlaps += openings[i] - closings[i];
  }

  std::vector<int> overlaps(n - d + 2);
  overlaps[1] = active_overlaps;
  for (int l = 2; l <= n - d + 1; ++l) {
    int r = l + d - 1;
    active_overlaps += openings[r] - closings[l];
    overlaps[l] = active_overlaps;
  }

  auto begin = overlaps.begin();
  auto end = overlaps.end();
  int brother_starting_day = std::max_element(begin + 1, end) - begin;
  int mother_starting_day = std::min_element(begin + 1, end) - begin;

  std::cout << brother_starting_day << ' ' << mother_starting_day << '\n';
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
