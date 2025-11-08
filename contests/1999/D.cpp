#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  while (T-- > 0) {
    std::string s, t;
    std::cin >> s >> t;

    int i = 0;
    int j = 0;
    while (i < s.length() && j < t.length()) {
      if (s[i] == '?') {
        s[i] = t[j];
      }
      if (s[i] == t[j]) {
        ++j;
      }
      ++i;
    }

    if (j < t.length()) {
      std::cout << "NO" << '\n';
      continue;
    }

    for (; i < s.length(); ++i) {
      if (s[i] == '?') {
        s[i] = 'a';
      }
    }

    std::cout << "YES\n" << s << '\n';
  }

  return 0;
}
