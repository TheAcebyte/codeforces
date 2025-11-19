#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

struct Monster {
  int health;
  int distance;
};

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<Monster> monsters(n);
  for (auto &monster : monsters) {
    std::cin >> monster.health;
  }

  for (auto& monster : monsters) {
    int distance;
    std::cin >> distance;
    monster.distance = std::abs(distance);
  }

  auto cmp = [&](Monster &a, Monster &b) { return a.distance < b.distance; };
  std::sort(monsters.begin(), monsters.end(), cmp);

  int carry = 0;
  int distance = 0;
  for (int i = 0; i < n; ++i) {
    Monster &monster = monsters[i];
    if (monster.health <= carry) {
      carry -= monster.health;
      continue;
    }

    int health = monster.health - carry;
    int threshold = monster.distance - distance;
    int required = ((u64)health + k - 1) / k;
    if (required > threshold) {
      std::cout << "NO\n";
      return;
    }

    distance += required;
    carry = required * k - health;
  }

  std::cout << "YES\n";
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
