#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#define M 1000000007

using i64 = std::int64_t;

void solve() {
  std::string s;
  std::cin >> s;

  std::vector<i64> dp;
  int count = 0;
  for (char c : s) {
    if (c == 'b' && count > 0) {
      dp.push_back(count);
      count = 0;
    } else if (c == 'a') {
      ++count;
    }
  }

  if (count > 0) {
    dp.push_back(count);
  }

  int n = dp.size();
  for (int i = n - 2; i >= 0; --i) {
    dp[i] = (dp[i] + dp[i + 1] + dp[i] * dp[i + 1]) % M;
  }

  int result = n > 0 ? dp[0] : 0;
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
