#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> last_index(n + 1, -1);
  std::vector<int> largest_excluding_group(n + 1);
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    int j = last_index[x];
    int group_size = i - j - 1;
    largest_excluding_group[x] =
        std::max(group_size, largest_excluding_group[x]);
    last_index[x] = i;
  }

  for (int x = 1; x <= n; ++x) {
    int i = last_index[x];
    int group_size = n - i - 1;
    largest_excluding_group[x] =
        std::max(group_size, largest_excluding_group[x]);
  }

  std::vector<int> result(n + 1, -1);
  int i = n;
  for (int x = 1; x <= n; ++x) {
    int group_size = largest_excluding_group[x];
    while (i > group_size) {
      result[i] = x;
      --i;
    }
  }

  const char *separator = "";
  for (int k = 1; k <= n; ++k) {
    std::cout << separator << result[k];
    separator = " ";
  }
  std::cout << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t-- > 0) {
    solve();
  }

  return 0;
}
