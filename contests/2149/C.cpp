#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }
  std::sort(a.begin(), a.end());

  int excluded = 0;
  int x = 0;
  int i = 0;
  while (x < k) {
    if (i < n && a[i] == x) {
      while (i < n && a[i] == x) {
        ++i;
      }
      ++x;
    } else {
      ++excluded;
      ++x;
    }
  }

  int included = 0;
  while (i < n && a[i] == k) {
    ++included;
    ++i;
  }

  int result = std::max(excluded, included);
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
