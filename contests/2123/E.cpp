#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

int mex(const std::vector<int> &a) {
  int n = a.size();
  std::vector<int> seen(n + 1);
  for (int x : a) {
    if (x <= n) {
      seen[x] = true;
    }
  }

  int m = std::find(seen.begin(), seen.end(), false) - seen.begin();
  return m;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  int m = mex(a);
  std::vector<std::pair<int, int>> count(m);
  for (int x : a) {
    if (x < m) {
      ++count[x].first;
      count[x].second = x;
    }
  }
  std::sort(count.begin(), count.end());

  std::set<int> reachable{m};
  int i = 0;
  const char *separator = "";
  for (int k = 0; k <= n; ++k) {
    reachable.erase(n - k + 1);
    while (i < m && k >= count[i].first) {
      int x = count[i].second;
      if (x <= n - k) {
        reachable.insert(x);
      }

      ++i;
    }

    int result = reachable.size();
    std::cout << separator << result;
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
