#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  std::map<int, int> occurrences;
  ++occurrences[0];
  int sum = 0;
  i64 result = 0;
  for (char c : s) {
    int x = c - '1';
    sum += x;
    result += occurrences[sum];
    ++occurrences[sum];
  }

  std::cout << result << '\n';
}

int main() {
#ifndef ONLINE_JUDGE 
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
