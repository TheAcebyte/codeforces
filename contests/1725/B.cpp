#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n, d;
  std::cin >> n >> d;

  std::vector<int> p(n);
  for (int &x : p) {
    std::cin >> x;
  }
  std::sort(p.begin(), p.end());

  int result = 0;
  int l = 0;
  int r = n - 1;
  while (l <= r) {
    int needed = d / p[r];
    if (l + needed > r) {
      break;
    }

    l += needed;
    --r;
    ++result;
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
