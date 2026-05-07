#include <iostream>
#include <vector>

void setmax(int& x, int y) { if (x < y) x = y; }

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int& x : a) { std::cin >> x; }

  auto is_reachable = [&](int i, int x) {
    int target = a[i] + x;
    int operations = 0;
    for (int j = i; j < n; ++j) {
      if (a[j] >= target) {
        return true;
      }

      operations += target - a[j];
      if (operations > k) {
        break;
      }

      --target;
    } 

    return false;
  };

  int result = 0;
  for (int i = 0; i < n; ++i) {
    int l = 0;
    int r = k;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (is_reachable(i, m)) {
        setmax(result, a[i] + m);
        l = m + 1;
      } else {
        r = m - 1;
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
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t-- > 0) {
    solve();
  }

  return 0;
}
