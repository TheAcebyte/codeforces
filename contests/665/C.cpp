#include <iostream>
#include <string>

char get_next_letter(char x) {
  char c = (x - 'a' + 1) % 26 + 'a';
  return c;
}

void solve() {
  std::string s;
  std::cin >> s;
  int n = s.length();

  int i = 0;
  while (i < n) {
    if (i < n - 1 && s[i + 1] == s[i]) {
      char c = get_next_letter(s[i]);
      if (i < n - 2 && s[i + 2] == c) {
        c = get_next_letter(c);
      }

      s[i + 1] = c;
      i += 2;
    } else {
      ++i;
    }
  }

  std::cout << s << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  solve();

  return 0;
}
