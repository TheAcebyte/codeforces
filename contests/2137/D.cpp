#include <iostream>
#include <unordered_map>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> b(n);
  std::unordered_map<int, std::pair<int, int>> distincts;
  for (int &x : b) {
    std::cin >> x;
    ++distincts[x].first;
  }

  for (auto &pair : distincts) {
    int key = pair.first;
    int count = pair.second.first;
    if (count % key != 0) {
      std::cout << -1 << '\n';
      return;
    }
  }

  int globalValue = 0;
  const char *separator = "";
  for (int i = 0; i < n; ++i) {
    int key = b[i];
    int &count = distincts[key].first;
    int &value = distincts[key].second;

    if (count % key == 0) {
      value = ++globalValue;
    }

    std::cout << separator << value;
    separator = " ";
    --count;
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
