#include <iostream>
#include <string>

void solve() {
  std::string s;
  std::cin >> s;

  int pairs = 0;
  int stack = 0;
  for (char c : s) {
    if (c == '0') {
      if (stack > 0) {
        ++pairs;
      }
      --stack;
    } else {
      if (stack < 0) {
        ++pairs;
      }
      ++stack;
    }
  }

  if (pairs & 1) {
    std::cout << "DA\n";
  } else {
    std::cout << "NET\n";
  }
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
