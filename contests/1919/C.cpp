#include <iostream>
#include <limits>
#include <vector>

constexpr int INF = std::numeric_limits<int>::max();

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  int s = INF;
  int t = INF;
  int penalties = 0;
  for (int x : a) {
    if (x <= s) {
      s = x;
    } else if (x <= t) {
      t = x;
    } else {
      s = t;
      t = x;
      ++penalties;
    }
  }

  int result = penalties;
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
