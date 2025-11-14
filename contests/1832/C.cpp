#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  int result = 1;
  int i = 1;
  while (i < n && a[i] == a[i - 1]) {
    ++i;
  }

  while (i < n) {
    if (a[i] > a[i - 1]) {
      while (i < n && a[i] >= a[i - 1]) {
        ++i;
      }
    } else {
      while (i < n && a[i] <= a[i - 1]) {
        ++i;
      }
    }

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

  int T;
  std::cin >> T;
  while (T-- > 0) {
    solve();
  }

  return 0;
}
