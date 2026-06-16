#include <iostream>
#include <string>

void solve() {
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;

  for (int i = 0; i < n - k; ++i) {
    if (s[i] == '1') {
      s[i] = '0';
      s[i + k] = 2 * '0' + 1 - s[i + k];
    }
  }

  auto i = s.find('1');
  if (i == std::string::npos) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
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
