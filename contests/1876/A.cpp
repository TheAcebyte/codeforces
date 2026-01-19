#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

struct Resident {
  int units;
  int cost;

  bool operator<(const Resident &other) const { return cost < other.cost; }
};

void solve() {
  int n, p;
  std::cin >> n >> p;

  std::vector<Resident> residents(n);
  for (auto &resident : residents) {
    std::cin >> resident.units;
  }
  for (auto &resident : residents) {
    std::cin >> resident.cost;
  }
  std::sort(residents.begin(), residents.end());

  u64 result = p;
  int remaining = n - 1;
  int i = 0;
  while (remaining > 0 && p > residents[i].cost) {
    if (remaining > residents[i].units) {
      result += (u64)residents[i].units * residents[i].cost;
      remaining -= residents[i].units;
    } else {
      result += (u64)remaining * residents[i].cost;
      remaining = 0;
    }

    ++i;
  }

  result += (u64)remaining * p;
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
