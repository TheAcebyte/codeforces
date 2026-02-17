#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  int opening = std::count(s.begin(), s.end(), '(');
  if (n % 2 == 1 || opening != n / 2) {
    std::cout << -1 << '\n';
    return;
  }

  int k = 1;
  std::vector<int> colors(n);

  bool beautiful = s[0] == ')';
  int color = 1;
  int stack = 0;
  int i = 0;
  while (i < n) {
    if (s[i] == '(') {
      --stack;
    } else {
      ++stack;
    }

    if ((!beautiful && stack > 0) || (beautiful && stack < 0)) {
      k = 2;
      color = 1 + color % 2;
      beautiful = !beautiful;
    }

    colors[i] = color;
    ++i;
  }

  std::cout << k << '\n';
  const char *separator = "";
  for (int color : colors) {
    std::cout << separator << color;
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
