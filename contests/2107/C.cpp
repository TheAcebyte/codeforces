#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using i64 = std::int64_t;

constexpr i64 inf = 1e12;
constexpr i64 zero = 0;

i64 max_subarray_sum(const std::vector<i64>& a) {
  i64 result = a[0];
  i64 sum = 0;
  for (i64 x : a) {
    sum += x;
    result = std::max(sum, result);
    sum = std::max(zero, sum);
  }

  return result;
}

void solve() {
  int n;
  i64 k;
  std::string s;
  std::cin >> n >> k >> s;

  bool has_missing_parts = false;
  std::vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (s[i] == '0') {
      a[i] = -inf;
      has_missing_parts = true;
    }
  }

  i64 sum = max_subarray_sum(a);
  if (sum > k || (sum < k && !has_missing_parts)) {
    std::cout << "NO\n";
    return;
  }

  if (sum < k) {
    int i = std::find(s.begin(), s.end(), '0') - s.begin();
    int j;

    j = i - 1;
    i64 left_sum = 0;
    i64 max_left_sum = 0;
    while (j >= 0) {
      left_sum += a[j--];
      max_left_sum = std::max(left_sum, max_left_sum);
    }

    j = i + 1;
    i64 right_sum = 0;
    i64 max_right_sum = 0;
    while (j < n) {
      right_sum += a[j++];
      max_right_sum = std::max(right_sum, max_right_sum);
    }

    a[i] = k - max_left_sum - max_right_sum;
  }

  std::cout << "YES\n";
  const char* separator = "";
  for (i64 x : a) {
    std::cout << separator << x;
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
