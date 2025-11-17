#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

void solve() {
  int n;
  u64 h;
  std::cin >> n >> h;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  auto get_damage = [&](u64 duration) {
    u64 damage = duration;
    for (int i = n - 1; i > 0; --i) {
      damage += std::min(duration, (u64)a[i] - a[i - 1]);
    }

    return damage;
  };

  u64 low = 0;
  u64 high = h;
  while (low < high) {
    u64 middle = low + (high - low) / 2;
    u64 damage = get_damage(middle);
    if (damage >= h) {
      high = middle;
    } else {
      low = middle + 1;
    }
  }

  std::cout << high << '\n';
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
