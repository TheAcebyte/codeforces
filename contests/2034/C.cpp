#include <iostream>
#include <map>
#include <string>
#include <vector>

struct cell {
  int row;
  int col;
};

std::map<char, cell> moves{
    {'L', {0, -1}}, {'R', {0, 1}}, {'D', {1, 0}}, {'U', {-1, 0}}};

std::map<char, char> reverse_directions{
    {'L', 'R'}, {'R', 'L'}, {'U', 'D'}, {'D', 'U'}};

void count_exiting_paths(const std::vector<std::string> &directions,
                         std::vector<std::vector<int>> &count, int row,
                         int col) {
  int n = directions.size();
  int m = directions.front().size();

  for (auto [d, move] : moves) {
    int next_row = row + move.row;
    int next_col = col + move.col;
    if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) {
      continue;
    }

    char next_direction = directions[next_row][next_col];
    if (next_direction == '?') {
      ++count[next_row][next_col];
    } else if (next_direction == reverse_directions[d]) {
      ++count[next_row][next_col];
      count_exiting_paths(directions, count, next_row, next_col);
    }
  }
}

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> directions(n);
  for (auto &direction : directions) {
    std::cin >> direction;
  }

  std::vector<std::vector<int>> count(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    count_exiting_paths(directions, count, i, -1);
    count_exiting_paths(directions, count, i, m);
  }

  for (int j = 0; j < m; ++j) {
    count_exiting_paths(directions, count, -1, j);
    count_exiting_paths(directions, count, n, j);
  }

  int result = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (count[i][j] == 0 || (directions[i][j] == '?' && count[i][j] < 4)) {
        ++result;
      }
    }
  }

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
