#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (i > 0 && i < n - 1 && a[i] == -1) {
      a[i] = 0;
    }
  }

  if (a[0] == -1 && a[n - 1] == -1) {
    a[0] = a[n - 1] = 0;
  } else if (a[0] == -1) {
    a[0] = a[n - 1];
  } else if (a[n - 1] == -1) {
    a[n - 1] = a[0];
  }

  int difference = 0;
  for (int i = 0; i < n - 1; ++i) {
    difference += a[i + 1] - a[i];
  }

  int result = std::abs(difference);
  std::cout << result << '\n';

  const char *separator = "";
  for (int x : a) {
    std::cout << separator << x;
    separator = " ";
  }
  std::cout << '\n';
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
