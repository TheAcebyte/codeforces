#include <algorithm>
#include <iostream>

void solve() {
  int n;
  std::cin >> n;

  int nonZeroSubarrays = 0;
  bool nonZeroGroup = false;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    if (x == 0 && nonZeroGroup) {
      ++nonZeroSubarrays;
    }

    nonZeroGroup = x != 0;
  }

  if (nonZeroGroup) {
    ++nonZeroSubarrays;
  }

  int result = std::min(nonZeroSubarrays, 2);
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
