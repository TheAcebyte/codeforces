#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

void solve() {
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;

  std::vector<char> block(k, '?');
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?') {
      continue;
    }

    int j = i % k;
    if (block[j] != '?' && block[j] != s[i]) {
      std::cout << "NO\n";
      return;
    }

    block[j] = s[i];
  }

  int zeros = 0;
  int ones = 0;
  int wildcards = 0;
  for (char c : block) {
    if (c == '0') {
      ++zeros;
    } else if (c == '1') {
      ++ones;
    } else {
      ++wildcards;
    }
  }

  if (std::abs(zeros - ones) > wildcards) {
    std::cout << "NO\n";
    return;
  }

  std::cout << "YES\n";
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
