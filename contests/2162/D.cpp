#include <iostream>

int calculate_increments(int l, int r) {
  int s, t;
  std::cout << "1 " << l << ' ' << r << std::endl;
  std::cin >> s;
  std::cout << "2 " << l << ' ' << r << std::endl;
  std::cin >> t;
  return t - s;
}

void solve() {
  int n;
  std::cin >> n;

  int length = calculate_increments(1, n);
  int r;
  int low = 1;
  int high = n;
  while (low <= high) {
    int m = low + (high - low) / 2;
    int partial_length = calculate_increments(1, m);
    if (partial_length == length) {
      r = m;
      high = m - 1;
    } else {
      low = m + 1;
    }
  }

  int l = r - length + 1;
  std::cout << "! " << l << ' ' << r << std::endl;
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
