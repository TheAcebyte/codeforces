#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> tasks(n);
  for (int i = 0; i < m; ++i) {
    int worker;
    std::cin >> worker;
    --worker;
    ++tasks[worker];
  }
  std::sort(tasks.rbegin(), tasks.rend());

  int result;
  int low = 0;
  int high = m;
  while (low <= high) {
    int time = low + (high - low) / 2;
    int spare_tasks = 0;

    for (int worker = 0; worker < n; ++worker) {
      if (time >= tasks[worker]) {
        int remaining_time = time - tasks[worker];
        int additional_tasks = remaining_time / 2;
        if (spare_tasks > additional_tasks) {
          spare_tasks -= additional_tasks;
        } else {
          spare_tasks = 0;
        }
      } else {
        spare_tasks += tasks[worker] - time;
      }
    }

    if (spare_tasks > 0) {
      low = time + 1;
    } else {
      result = time;
      high = time - 1;
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
