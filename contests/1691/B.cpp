#include <iostream>
#include <map>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int& x : a ) {
    std::cin >> x;
  }

  std::map<int, int> lastIndex;
  std::vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    if (lastIndex.count(x)) {
      p[i] = lastIndex[x];
    }

    lastIndex[x] = i + 1;
  }

  for (int i = 0; i < n; ++i) {
    if (p[i] != 0) {
      continue;
    }

    int x = a[i];
    p[i] = lastIndex[x];
    if (p[i] == i + 1) {
      std::cout << -1 << '\n';
      return;
    }
  }

  const char* separator = "";
  for (int i : p) {
    std::cout << separator << i;
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
