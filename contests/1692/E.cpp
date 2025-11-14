#include <iostream>
#include <vector>

void solve() {
  int n, s;
  std::cin >> n >> s;

  std::vector<int> prefix(n + 1);
  prefix[0] = 0;

  for (int i = 1; i <= n; ++i) {
    int bit;
    std::cin >> bit;
    prefix[i] = bit + prefix[i - 1];
  }

  int result = -1;
  for (int l = 0; l <= n; ++l) {
    int r = -1;
    int low = l + 1;
    int high = n;
    while (low <= high) {
      int middle = low + (high - low) / 2;
      int sum = prefix[middle] - prefix[l];
      if (sum == s) {
        r = middle;
        low = middle + 1;
      } else if (sum < s) {
        low = middle + 1;
      } else {
        high = middle - 1;
      }
    }

    if (r == -1) {
      continue;
    }

    int operations = l + n - r;
    if (result == -1 || operations < result) {
      result = operations;
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
