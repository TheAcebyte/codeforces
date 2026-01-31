#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int& x : a) {
    std::cin >> x;
  }

  std::vector<int> result(n);
  int l = 0;
  int r = 0;
  while (r < n) {
    if (a[l] < r - l + 1) {
      ++l;
    }

    result[r] = r - l + 1;
    ++r;
  }

  const char* separator = "";
  for (int x : result) {
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
