#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  int result = -1;
  int element = a[0];
  bool unique = true;
  for (int i = 0; i < n; ++i) {
    int count = 0;
    while (i < n && a[i] == element) {
      ++count;
      ++i;
    }

    if (i < n) {
      unique = false;
    }

    if (!unique && (result == -1 || count < result)) {
      result = count;
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
