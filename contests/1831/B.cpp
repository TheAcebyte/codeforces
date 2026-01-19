#include <algorithm>
#include <iostream>
#include <map>
#include <utility>

void solve() {
  int n;
  std::cin >> n;
  std::map<int, std::pair<int, int>> longestSequence;

  int last = -1;
  int count = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    if (x != last) {
      count = 0;
    }

    ++count;
    int& length = longestSequence[x].first;
    length = std::max(count, length);
    last = x;
  }

  last = -1;
  count = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    if (x != last) {
      count = 0;
    }

    ++count;
    int& length = longestSequence[x].second;
    length = std::max(count, length);
    last = x;
  }

  int result = -1;
  for (auto [x, length] : longestSequence) {
    if (result == -1) {
      result = length.first + length.second;
      continue;
    }

    result = std::max(length.first + length.second, result);
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
