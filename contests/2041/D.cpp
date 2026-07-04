#include <deque>
#include <iostream>
#include <vector>

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct state {
  int r;
  int c;
  int d;
  int s;
};

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> maze(n);
  for (auto &row : maze) std::cin >> row;

  int sr, sc, tr, tc;
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      if (maze[r][c] == 'S') {
        sr = r;
        sc = c;
      } else if (maze[r][c] == 'T') {
        tr = r;
        tc = c;
      }
    }
  }

  std::vector<std::vector<std::vector<std::vector<bool>>>> seen(
      n,
      std::vector<std::vector<std::vector<bool>>>(
          m, std::vector<std::vector<bool>>(4, std::vector<bool>(4, false))));

  std::deque<state> queue{{sr, sc, 0, 0}};
  int min_steps = -1;
  int total_steps = 0;
  while (!queue.empty() && min_steps < 0) {
    int k = queue.size();
    for (int i = 0; i < k; ++i) {
      auto [r, c, d, s] = queue.front();
      queue.pop_front();
      if (r == tr && c == tc) {
        min_steps = total_steps;
        break;
      }

      for (int nd = 0; nd < 4; ++nd) {
        int nr = r + dr[nd];
        int nc = c + dc[nd];
        int ns = 1 + (nd == d ? s : 0);
        if (nr < 0 || nr >= n || nc < 0 || nc >= m || maze[nr][nc] == '#' ||
            ns > 3 || seen[nr][nc][nd][ns]) {
          continue;
        }

        seen[nr][nc][nd][ns] = true;
        state new_state{nr, nc, nd, ns};
        queue.push_back(new_state);
      }
    }

    ++total_steps;
  }

  std::cout << min_steps << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
