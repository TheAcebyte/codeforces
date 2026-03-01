#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  auto query_path_length = [&](int x) {
    std::cout << "? " << x << ' ' << n;
    for (int s = 1; s <= n; ++s) {
      std::cout << ' ' << s;
    }
    std::cout << std::endl;

    int path_length;
    std::cin >> path_length;

    return path_length;
  };

  auto query_edge = [&](int u, int v) {
    std::cout << "? " << u << " 2 " << u << ' ' << v << std::endl;

    int path_length;
    std::cin >> path_length;

    return path_length == 2;
  };

  int max_path_length = 0;
  std::vector<std::vector<int>> path(n + 1);

  for (int x = 1; x <= n; ++x) {
    int path_length = query_path_length(x);
    path[path_length].push_back(x);
    max_path_length = std::max(path_length, max_path_length);
  }

  int l = max_path_length;
  std::vector<int> result(l);
  result[0] = path[l][0];
  for (int i = 1; i < l; ++i) {
    int u = result[i - 1];
    for (int v : path[l - i]) {
      bool is_connected = query_edge(u, v);
      if (is_connected) {
        result[i] = v;
        break;
      }
    }
  }

  std::cout << "! " << l;
  for (int u : result) {
    std::cout << ' ' << u;
  }
  std::cout << std::endl;
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
