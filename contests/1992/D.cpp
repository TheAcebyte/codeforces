#include <iostream>
#include <string>

enum Map : char {
  LOG = 'L',
  WATER = 'W',
  CROCODILE = 'C',
};

void solve() {
  int n, m, k;
  std::string map;
  std::cin >> n >> m >> k >> map;

  map.insert(map.begin(), Map::LOG);
  ++n;

  int p = 0;
  while (p < n && map[p] != Map::CROCODILE &&
         !(map[p] == Map::WATER && k == 0)) {
    if (map[p] == Map::WATER) {
      ++p;
      --k;
    } else if (p + m >= n) {
      p = n;
    } else {
      int log = -1;
      int water = -1;

      for (int i = p + 1; i <= p + m; ++i) {
        if (map[i] == Map::LOG && log == -1) {
          log = i;
        } else if (map[i] == Map::WATER) {
          water = i;
        }
      }

      if (log == -1 && water == -1) {
        break;
      }

      if (log != -1) {
        p = log;
      } else {
        p = water;
      }
    }
  }

  std::cout << (p >= n ? "YES" : "NO") << '\n';
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
