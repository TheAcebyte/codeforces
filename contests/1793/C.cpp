#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> p(n);
  for (int &x : p) {
    std::cin >> x;
  }

  int min = 1;
  int max = n;

  int left = 0;
  int right = n - 1;
  while (left < right) {
    if (p[left] == min) {
      ++left;
      ++min;
    } else if (p[left] == max) {
      ++left;
      --max;
    } else if (p[right] == min) {
      --right;
      ++min;
    } else if (p[right] == max) {
      --right;
      --max;
    } else {
      break;
    }
  }

  if (left >= right) {
    std::cout << -1 << '\n';
  } else {
    std::cout << left + 1 << ' ' << right + 1 << '\n';
  }
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
