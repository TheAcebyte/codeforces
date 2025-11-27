#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> deck(n * m);
  std::vector<int> permutation(n);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int card;
      std::cin >> card;
      deck[card] = i;
    }
  }

  std::copy(deck.begin(), deck.begin() + n, permutation.begin());
  for (int j = 1; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      if (deck[j * n + i] != permutation[i]) {
        std::cout << -1 << '\n';
        return;
      }
    }
  }

  const char *separator = "";
  for (int turn : permutation) {
    std::cout << separator << turn + 1;
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
