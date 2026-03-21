#include <iostream>
#include <string>

void solve() {
  std::string s;
  std::cin >> s;
  int n = s.length();

  int l = (n - 1) / 2;
  int r = n / 2;
  while (l > 0) {
    int k = r - l + 1;
    std::string left = s.substr(0, r + 1);
    std::string right = s.substr(l, n - l);

    int m = left.size();
    std::string ending_overlap = left.substr(m - k, k);
    std::string starting_overlap = right.substr(0, k);
    if (left == right && starting_overlap == ending_overlap) {
      std::cout << "YES\n";
      std::cout << left << '\n';
      return;
    }

    --l;
    ++r;
  }

  std::cout << "NO\n";
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
