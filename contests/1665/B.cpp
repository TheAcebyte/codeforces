#include <iostream>
#include <map>

void solve() {
  int n;
  std::cin >> n;

  std::map<int, int> count;
  int maxCount = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ++count[x];

    if (count[x] > maxCount) {
      maxCount = count[x];
    }
  }

  int result = 0;
  int remaining = n - maxCount;
  while (remaining > maxCount) {
    result += 1 + maxCount;
    remaining -= maxCount;
    maxCount *= 2;
  }

  if (remaining > 0) {
    result += 1 + remaining;
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
