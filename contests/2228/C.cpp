#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using i64 = std::int64_t;
constexpr i64 INF = 1e18;

void solve() {
  std::string a;
  int n;
  std::cin >> a >> n;

  std::vector<char> digits(n);
  for (char &d : digits) std::cin >> d;

  i64 result = INF;
  std::string b;
  auto pad_and_test = [&](int m, char d) {
    if (m <= 0) return;

    int l = b.length();
    while ((int)b.length() < m) {
      b.push_back(d);
    }

    i64 x = std::stoll(a);
    i64 y = std::stoll(b);
    i64 difference = std::abs(x - y);
    result = std::min(difference, result);
    b.resize(l);
  };

  int m = a.length();
  pad_and_test(m - 1, digits.back());
  if (n > 1 || digits.front() != '0') {
    b.push_back(digits[0] == '0' ? digits[1] : digits[0]);
    pad_and_test(m + 1, digits.front());
    b.pop_back();
  }

  int i = 0;
  while (i < m) {
    auto gt_it = std::upper_bound(digits.begin(), digits.end(), a[i]);
    if (gt_it != digits.end()) {
      b.push_back(*gt_it);
      pad_and_test(m, digits.front());
      b.pop_back();
    }

    auto gte_it = std::lower_bound(digits.begin(), digits.end(), a[i]);
    if (gte_it != digits.begin()) {
      auto lt_it = gte_it - 1;
      b.push_back(*lt_it);
      pad_and_test(m, digits.back());
      b.pop_back();
    }

    if (gte_it == digits.end() || *gte_it != a[i]) {
      break;
    }

    b.push_back(a[i++]);
  }

  pad_and_test(b.size(), '0');
  std::cout << result << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  // if (t == 4) {
    while (t-- > 0) {
      solve();
    }
  // } else {
  //   for (int i = 1; i <= t; ++i) {
  //     i64 a, n;
  //     std::cin >> a >> n;
  //
  //     std::vector<int> digits(n);
  //     for (int &d : digits) std::cin >> d;
  //
  //     if (i == 6141) {
  //       std::cout << a << ' ' << n << '\n';
  //       for (int d : digits) std::cout << d << ' ';
  //     }
  //   }
  // }

  return 0;
}
