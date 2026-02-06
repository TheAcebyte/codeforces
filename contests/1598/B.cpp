#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

#define DAYS 5

constexpr std::array<bool, DAYS> defaultAttendance{
    {false, false, false, false, false}};

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::array<bool, DAYS>> attended(n, defaultAttendance);
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < DAYS; ++i) {
      std::cin >> attended[k][i];
    }
  }

  for (int i = 0; i < DAYS; ++i) {
    for (int j = i + 1; j < DAYS; ++j) {
      bool convenient = true;
      int first = 0;
      int second = 0;
      for (int k = 0; k < n; ++k) {
        if (!attended[k][i] && !attended[k][j]) {
          convenient = false;
          break;
        }

        if (attended[k][i]) {
          ++first;
        }

        if (attended[k][j]) {
          ++second;
        }
      }

      bool divisible = std::min(first, second) >= n / 2;
      if (convenient && divisible) {
        std::cout << "YES\n";
        return;
      }
    }
  }

  std::cout << "NO\n";
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
