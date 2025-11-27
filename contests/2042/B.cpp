#include <iostream>
#include <set>

int ceil(int a, int b) { return (a + b - 1) / b; }

void solve() {
  int n;
  std::cin >> n;

  std::set<int> uniques, duplicates;
  for (int i = 0; i < n; ++i) {
    int c;
    std::cin >> c;

    if (uniques.count(c)) {
      uniques.erase(c);
      duplicates.insert(c);
    } else if (!duplicates.count(c)) {
      uniques.insert(c);
    }
  }

  int result = 2 * ceil(uniques.size(), 2) + duplicates.size();
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
