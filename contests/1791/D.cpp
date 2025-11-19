#include <bitset>
#include <iostream>
#include <string>
#include <vector>

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  std::bitset<26> occurences;
  std::vector<int> prefix(n + 1);
  for (int i = 1; i <= n; ++i) {
    int index = s[i - 1] - 'a';
    occurences.set(index);
    prefix[i] = occurences.count();
  }

  occurences = 0;
  std::vector<int> suffix(n + 1);
  for (int i = n - 1; i >= 0; --i) {
    int index = s[i] - 'a';
    occurences.set(index);
    suffix[i] = occurences.count();
  }

  int result = 0;
  for (int i = 1; i < n; ++i) {
    int count = prefix[i] + suffix[i];
    result = std::max(count, result);
  }

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
