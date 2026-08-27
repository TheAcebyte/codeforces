#include <array>
#include <iostream>
#include <string>
#include <vector>

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::array<bool, 26> letters;
  letters.fill(false);
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    letters[s[0] - 'a'] = true;
  }

  std::vector<std::string> abbreviations(m);
  for (auto& s : abbreviations) std::cin >> s;
  for (const auto& s : abbreviations) {
    for (char c : s) {
      if (!letters[c - 'A']) {
        std::cout << "NO\n";
        return;
      }
    }
  }

  std::cout << "YES\n";
}

int main() {
#ifndef ONLINE_JUDGE
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
