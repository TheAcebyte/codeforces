#include <algorithm>
#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  while (T-- > 0) {
    int n;
    std::string s;
    std::cin >> n >> s;

    int zeros = std::count(s.begin(), s.end(), '0');
    if (zeros % 2 == 0 || zeros == 1) {
      std::cout << "BOB\n";
    } else {
      std::cout << "ALICE\n";
    }
  }

  return 0;
}
