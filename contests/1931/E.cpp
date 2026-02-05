#include <algorithm>
#include <deque>
#include <iostream>
#include <utility>

int get_digit_count(int x) {
  if (x == 0) {
    return 1;
  }

  int count = 0;
  while (x > 0) {
    ++count;
    x /= 10;
  }

  return count;
}

int get_trailing_zeros(int x) {
  if (x == 0) {
    return 1;
  }

  int count = 0;
  while (x % 10 == 0) {
    ++count;
    x /= 10;
  }

  return count;
}

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::deque<std::pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    a[i].first = get_trailing_zeros(x);
    a[i].second = get_digit_count(x);
  }
  std::sort(a.rbegin(), a.rend());

  while (a.size() > 1) {
    auto x = a.front();
    a.pop_front();
    auto y = a.front();
    a.pop_front();
    a.emplace_back(0, y.second + x.second - x.first);
  }

  auto x = a.front();
  int digits = x.second - x.first;
  if (digits > m) {
    std::cout << "Sasha\n";
  } else {
    std::cout << "Anna\n";
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
