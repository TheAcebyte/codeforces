#include <iostream>
#include <string>
#include <vector>

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  std::vector<int> empty_pots;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      empty_pots.push_back(i);
    }
  }

  int m = empty_pots.size();
  if (m == 0) {
    std::cout << "YES\n";
    return;
  }

  bool left = true;
  bool right = empty_pots[m - 1] == n - 1;
  for (int j = m - 2; j >= 0; --j) {
    int i = empty_pots[j];
    int r = empty_pots[j + 1];
    int flowers = r - i - 1;

    bool next_left = left;
    bool next_right = right;
    if (flowers > 1) {
      left = next_right;
      right = false;
    } else if (flowers == 1) {
      left = next_right;
      right = next_left;
    } else {
      left = right = next_left || next_right;
    }
  }

  bool result = right;
  if (empty_pots[0] == 0) {
    result = result || left;
  }

  if (result) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
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
