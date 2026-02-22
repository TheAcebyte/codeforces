#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  bool end_to_end = true;
  std::vector<bool> present(n + 1);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    if (x <= n) {
      present[x] = true;
    } else {
      end_to_end = false;
    }
  }

  int x = 1;
  while (x <= n && present[x]) {
    ++x;
  }

  int length = x - 1;
  if (end_to_end &&
      std::find(present.begin() + x, present.end(), true) != present.end()) {
    end_to_end = false;
  }

  if (end_to_end) {
    if (length & 1) {
      std::cout << "Alice\n";
    } else {
      std::cout << "Bob\n";
    }
  } else {
    if (length & 1) {
      std::cout << "Bob\n";
    } else {
      std::cout << "Alice\n";
    }
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
