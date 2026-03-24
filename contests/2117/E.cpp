#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> b(n);
  for (int &y : b) {
    std::cin >> y;
  }

  std::vector<std::pair<int, int>> last_index(n + 1, {-1, -1});
  int result = 0;
  for (int i = n - 1; i >= 0; --i) {
    int x = a[i];
    int y = b[i];
    int &xi = last_index[x].first;
    int &xc = last_index[x].second;
    int &yi = last_index[y].first;
    int &yc = last_index[y].second;

    if (x == y) {
      result = std::max(i + 1, result);
    } else {
      if (xi == -1) {
        xi = i;
        xc = 0;
      } else if (xi != i + 1 || xc == 0) {
        result = std::max(i + 1, result);
      }

      if (yi == -1) {
        yi = i;
        yc = 1;
      } else if (yi != i + 1 || yc == 1) {
        result = std::max(i + 1, result);
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
