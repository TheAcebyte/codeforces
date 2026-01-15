#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> b(n);
  for (int &x : b) {
    std::cin >> x;
  }

  bool foundChange = b[0] != a[0];
  bool appliedChange = false;
  int optimalStart = 0;
  int optimalEnd = 0;
  int start = 0;
  for (int i = 1; i < n; ++i) {
    if (b[i] < b[i - 1]) {
      if (foundChange) {
        optimalStart = start;
        optimalEnd = i - 1;
        appliedChange = true;
        break;
      }

      if (i - start > optimalEnd - optimalStart + 1) {
        optimalStart = start;
        optimalEnd = i - 1;
      }

      start = i;
    }

    if (b[i] != a[i]) {
      foundChange = true;
    }
  }

  if ((foundChange && !appliedChange) ||
      (!foundChange && n - start > optimalEnd - optimalStart + 1)) {
    optimalStart = start;
    optimalEnd = n - 1;
  }

  ++optimalStart;
  ++optimalEnd;
  std::cout << optimalStart << ' ' << optimalEnd << '\n';
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
