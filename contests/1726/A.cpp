#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  if (n == 1) {
    int x;
    std::cin >> x;
    std::cout << 0 << '\n';
    return;
  }

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  int leftMin = a[0];
  for (int i = 0; i < n - 1; ++i) {
    leftMin = std::min(a[i], leftMin);
  }

  int rightMax = a[n - 1];
  for (int i = 1; i < n; ++i) {
    rightMax = std::max(a[i], rightMax);
  }

  int maxConsecutiveDifference = 0;
  for (int i = 0; i < n - 1; ++i) {
    maxConsecutiveDifference =
        std::max(a[i] - a[i + 1], maxConsecutiveDifference);
  }

  int result = std::max(maxConsecutiveDifference,
                        std::max(a[n - 1] - leftMin, rightMax - a[0]));
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
