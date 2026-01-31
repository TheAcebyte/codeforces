#include <iostream>
#include <map>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::map<int, int> count;
  std::vector<std::vector<int>> p(n);
  for (auto& c : p) {
    int k;
    std::cin >> k;

    c.resize(k);
    for (int i = 0; i < k; ++i) {
      std::cin >> c[i];
      ++count[c[i]];
    }
  }

  for (auto& c : p) {
    bool necessary = false;
    int k = c.size();
    for (int i = 0; i < k; ++i) {
      if (count[c[i]] == 1) {
        necessary = true;
        break;
      }
    }

    if (!necessary) {
      std::cout << "YES\n";
      return;
    }
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
