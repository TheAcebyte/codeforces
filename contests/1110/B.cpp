#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<int> b(n);
  for (int &x : b) {
    std::cin >> x;
  }

  std::vector<int> differences(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    differences[i] = b[i + 1] - b[i] - 1;
  }
  std::sort(differences.rbegin(), differences.rend());

  i64 result = b[n - 1] - b[0] + 1;
  for (int i = 0; i < k - 1; ++i) {
    result -= differences[i];
  }

  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  solve();

  return 0;
}
