#include <iostream>
#include <set>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> b(n);
  for (int& x : b) {
    std::cin >> x;
  }

  std::set<int> seen;
  for (int& x : b) {
    if (seen.count(x)) {
      std::cout << "YES\n";
      return;
    }
    seen.insert(x);
  }

  std::cout << "NO\n";
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
