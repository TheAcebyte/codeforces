#include <array>
#include <iostream>
#include <string>

void solve() {
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;

  std::array<int, 26> counts;
  counts.fill(0);
  for (char c : s) {
    ++counts[c - 'a'];
  }

  int odds = 0;
  for (int count : counts) {
    if (count & 1) {
      ++odds;
    }
  }

  if (k < odds - 1) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
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
