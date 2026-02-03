#include <iostream>
#include <vector>

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  int result = 0;
  for (int j = 30; j >= 0; --j) {
    int zeros = 0;
    for (int x : a) {
      if (((x >> j) & 1) == 0) {
        ++zeros;
      }
    }

    if (zeros <= k) {
      k -= zeros;
      result |= 1 << j;
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
