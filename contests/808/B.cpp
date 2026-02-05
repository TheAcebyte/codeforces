#include <iostream>
#include <vector>

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  double running_sum = 0;
  for (int i = 0; i < k - 1; ++i) {
    running_sum += a[i];
  }

  double total_sum = 0;
  int l = 0;
  for (int r = k - 1; r < n; ++r) {
    running_sum += a[r];
    total_sum += running_sum;
    running_sum -= a[l++];
  }

  double result = total_sum / (n - k + 1);
  std::cout << std::fixed << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  solve();

  return 0;
}
