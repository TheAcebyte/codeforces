#include <algorithm>
#include <iostream>
#include <map>

int mod(int x, int m) {
  int result = x % m;
  return result < 0 ? result + m : result;
}

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::map<int, int> remainders;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ++remainders[x % m];
  }

  int result = 0;
  for (int x = 0; x <= m / 2; ++x) {
    int y = mod(m - x, m);
    int min = std::min(remainders[x], remainders[y]);
    int max = std::max(remainders[x], remainders[y]);

    if (max == 0) {
      continue;
    }

    ++result;
    if (max > min + 1) {
      result += max - min - 1;
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
