#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> b(m);
  for (int &x : b) {
    std::cin >> x;
  }

  std::vector<int> a_ones;
  int group_size = 0;
  for (int x : a) {
    if (x == 1) {
      ++group_size;
    } else if (group_size > 0) {
      a_ones.push_back(group_size);
      group_size = 0;
    }
  }

  if (group_size > 0) {
    a_ones.push_back(group_size);
  }

  std::vector<int> b_ones;
  group_size = 0;
  for (int x : b) {
    if (x == 1) {
      ++group_size;
    } else if (group_size > 0) {
      b_ones.push_back(group_size);
      group_size = 0;
    }
  }

  if (group_size > 0) {
    b_ones.push_back(group_size);
  }

  std::sort(a_ones.begin(), a_ones.end());
  std::sort(b_ones.begin(), b_ones.end());

  int pn = a_ones.size();
  std::vector<int> a_ones_suffix(a_ones);
  for (int i = pn - 2; i >= 0; --i) {
    a_ones_suffix[i] += a_ones_suffix[i + 1];
  }

  int pm = b_ones.size();
  std::vector<int> b_ones_suffix(b_ones);
  for (int i = pm - 2; i >= 0; --i) {
    b_ones_suffix[i] += b_ones_suffix[i + 1];
  }

  auto count_rectangles = [&](int x, int y) -> i64 {
    int i = std::lower_bound(a_ones.begin(), a_ones.end(), y) - a_ones.begin();
    int j = std::lower_bound(b_ones.begin(), b_ones.end(), x) - b_ones.begin();
    if (i >= pn || j >= pm) {
      return 0;
    }

    i64 dy = a_ones_suffix[i] + (i64)(pn - i) * (1 - y);
    i64 dx = b_ones_suffix[j] + (i64)(pm - j) * (1 - x);
    return dx * dy;
  };

  i64 result = 0;
  int x = 1;
  for (; x * x < k; ++x) {
    if (k % x == 0) {
      int y = k / x;
      result += count_rectangles(x, y) + count_rectangles(y, x);
    }
  }

  if (x * x == k) {
    result += count_rectangles(x, x);
  }

  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
