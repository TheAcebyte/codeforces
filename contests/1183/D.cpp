#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

constexpr int INF = std::numeric_limits<int>::max();

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> counter(n + 1);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ++counter[x];
  }
  std::sort(counter.rbegin(), counter.rend());

  int k = INF;
  int result = 0;
  for (int i = 0; i < n && k > 0; ++i) {
    int c = counter[i];
    k = std::min(c, k - 1);
    result += k;
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
