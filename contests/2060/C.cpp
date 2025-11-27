#include <iostream>
#include <map>

void solve() {
  int n, k;
  std::cin >> n >> k;

  int result = 0;
  std::map<int, int> complements;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    if (complements[x] > 0) {
      ++result;
      --complements[x];
    } else {
      ++complements[k - x];
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
