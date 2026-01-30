#include <algorithm>
#include <iostream>
#include <vector>

struct Casino {
  int l;
  int r;
  int x;

  bool operator<(const Casino& other) const { return x < other.x; }
};

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<Casino> casinos(n);
  for (auto& casino : casinos) {
    std::cin >> casino.l >> casino.r >> casino.x;
  }
  std::sort(casinos.begin(), casinos.end());

  int coins = k;
  for (const auto& casino : casinos) {
    if (coins >= casino.l && coins <= casino.r && coins < casino.x) {
      coins = casino.x;
    }
  }

  int result = coins;
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
