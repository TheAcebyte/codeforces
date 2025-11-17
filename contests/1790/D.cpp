#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }
  std::sort(a.begin(), a.end());

  int sets = 0;
  int previousCount = 0;
  int i = 0;
  while (i < n) {
    if (i > 0 && a[i] > a[i - 1] + 1) {
      sets += previousCount;
      previousCount = 0;
    }

    int count = 1;
    while (i < n - 1 && a[i + 1] == a[i]) {
      ++count;
      ++i;
    }

    if (count < previousCount) {
      sets += previousCount - count;
    }

    previousCount = count;
    ++i;
  }

  int result = sets + previousCount;
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
