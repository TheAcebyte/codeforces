#include <array>
#include <iostream>
#include <string>

void solve() {
  std::string w;
  int p;
  std::cin >> w >> p;

  std::array<int, 26> count;
  count.fill(0);

  int price = 0;
  for (char c : w) {
    price += c - 'a' + 1;
    ++count[c - 'a'];
  }

  std::array<int, 26> removed;
  removed.fill(0);

  int difference = price - p;
  int i = 'z' - 'a';
  while (i >= 0 && difference > 0) {
    if (count[i] > 0) {
      difference -= i + 1;
      ++removed[i];
      --count[i];
    } else {
      --i;
    }
  }

  for (char c : w) {
    if (removed[c - 'a'] > 0) {
      --removed[c - 'a'];
      continue;
    }

    std::cout << c;
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
