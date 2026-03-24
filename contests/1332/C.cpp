#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

void solve() {
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;

  std::vector<std::array<int, 26>> count(k, {{}});
  for (int i = 0; i < n; ++i) {
    int j = i % k;
    int c = s[i] - 'a';
    ++count[j][c];
  }

  int groups = n / k;
  int result = 0;
  int l = 0;
  int r = k - 1;
  while (l < r) {
    int min_cost = 2 * groups;
    for (char c = 0; c < 26; ++c) {
      int cost = 2 * groups - count[l][c] - count[r][c];
      min_cost = std::min(cost, min_cost);
    }

    result += min_cost;
    ++l;
    --r;
  }

  if (l == r) {
    int max_count = *std::max_element(count[l].begin(), count[l].end());
    result += groups - max_count;
  }

  std::cout << result << '\n';
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
