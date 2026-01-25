#include <iostream>
#include <vector>

void solve() {
  int n, x;
  std::cin >> n >> x;

  std::vector<int> a(n);
  for (int& n : a) {
    std::cin >> n;
  }

  std::vector<int> b(n);
  for (int& n : b) {
    std::cin >> n;
  }

  std::vector<int> c(n);
  for (int& n : c) {
    std::cin >> n;
  }

  int y = 0;
  int i = 0;
  while (i < n && (~x & a[i]) == 0) {
    y |= a[i++];
  }

  int j = 0;
  while (j < n && (~x & b[j]) == 0) {
    y |= b[j++];
  }

  int k = 0;
  while (k < n && (~x & c[k]) == 0) {
    y |= c[k++];
  }

  if (y == x) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
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
