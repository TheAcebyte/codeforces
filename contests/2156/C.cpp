#include <iostream>
#include <vector>

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> counter(n + 1);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ++counter[x];
  }

  std::vector<int> suffix(n + 1);
  suffix[n] = counter[n];
  for (int i = n - 1; i >= 0; --i) {
    suffix[i] = suffix[i + 1] + counter[i];
  }

  int result = 1;
  for (int b = 1; b <= n; ++b) {
    int deletes = n - counter[b];
    if (2 * b <= n) deletes -= counter[2 * b];
    if (3 * b <= n) deletes -= counter[3 * b];
    if (4 * b <= n) deletes -= suffix[4 * b];

    if (deletes <= k) {
      result = b;
    }
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
