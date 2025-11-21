#include <iostream>
#include <map>
#include <numeric>

void solve() {
  int n;
  std::cin >> n;

  std::map<int, int> indices;
  for (int i = 1; i <= n; ++i) {
    int x;
    std::cin >> x;
    indices[x] = i;
  }

  int result = -1;
  for (auto &a : indices) {
    for (auto &b : indices) {
      if (std::gcd(a.first, b.first) == 1) {
        result = std::max(a.second + b.second, result);
      }
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
