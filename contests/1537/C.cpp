#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

void rotate(std::vector<int> &a, int k) {
  int n = a.size();
  std::vector<int> result(n);

  for (int i = 0; i < n; ++i) {
    int j = (i + k) % n;
    result[j] = a[i];
  }

  a = std::move(result);
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> heights(n);
  for (int &x : heights) {
    std::cin >> x;
  }

  if (n == 2) {
    int min = std::min(heights[0], heights[1]);
    int max = std::max(heights[0], heights[1]);
    std::cout << min << ' ' << max << '\n';
    return;
  }

  std::sort(heights.begin(), heights.end());

  int k = 0;
  int min = heights[n - 1] - heights[0];
  for (int i = 0; i < n - 1; ++i) {
    if (heights[i + 1] - heights[i] < min) {
      k = i;
      min = heights[i + 1] - heights[i];
    }
  }

  rotate(heights, n - k - 1);

  const char *separator = "";
  for (int h : heights) {
    std::cout << separator << h;
    separator = " ";
  }
  std::cout << '\n';
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
