#include <iostream>
#include <set>
#include <string>
#include <vector>

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> grid(n);
  for (auto &row : grid) {
    std::cin >> row;
  }

  std::vector<std::string> result(n, std::string(m, '.'));

  std::set<int> ignoreCols;
  for (int i = 0; i < n; ++i) {
    std::set<int> newIgnoreCols;
    int k = -1;
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'U' || (grid[i][j] == 'D' && !ignoreCols.count(j))) {
        if (k == -1) {
          k = j;
        } else if (grid[i][k] == 'U' && grid[i][j] == 'U') {
          result[i][k] = 'W';
          result[i + 1][k] = 'B';
          result[i][j] = 'B';
          result[i + 1][j] = 'W';
          newIgnoreCols.insert(k);
          newIgnoreCols.insert(j);
          k = -1;
        } else if (grid[i][k] == 'U' && grid[i][j] == 'D') {
          result[i][k] = result[i][j] == 'W' ? 'B' : 'W';
          result[i + 1][k] = result[i][k] == 'W' ? 'B' : 'W';
          k = -1;
        } else {
          result[i][j] = result[i][k] == 'W' ? 'B' : 'W';
          result[i + 1][j] = result[i][j] == 'W' ? 'B' : 'W';
          k = -1;
        }
      }
    }

    if (k != -1) {
      std::cout << -1 << '\n';
      return;
    }

    ignoreCols = std::move(newIgnoreCols);
  }

  std::set<int> ignoreRows;
  for (int j = 0; j < m; ++j) {
    std::set<int> newIgnoreRows;
    int k = -1;
    for (int i = 0; i < n; ++i) {
      if (grid[i][j] == 'L' || (grid[i][j] == 'R' && !ignoreRows.count(i))) {
        if (k == -1) {
          k = i;
        } else if (grid[k][j] == 'L' && grid[i][j] == 'L') {
          result[k][j] = 'W';
          result[k][j + 1] = 'B';
          result[i][j] = 'B';
          result[i][j + 1] = 'W';
          newIgnoreRows.insert(k);
          newIgnoreRows.insert(i);
          k = -1;
        } else if (grid[k][j] == 'L' && grid[i][j] == 'R') {
          result[k][j] = result[i][j] == 'W' ? 'B' : 'W';
          result[k][j + 1] = result[k][j] == 'W' ? 'B' : 'W';
          k = -1;
        } else {
          result[i][j] = result[k][j] == 'W' ? 'B' : 'W';
          result[i][j + 1] = result[i][j] == 'W' ? 'B' : 'W';
          k = -1;
        }
      }
    }

    if (k != -1) {
      std::cout << -1 << '\n';
      return;
    }

    ignoreRows = std::move(newIgnoreRows);
  }

  for (const auto &row : result) {
    std::cout << row << '\n';
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
