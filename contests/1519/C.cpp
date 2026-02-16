#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> u(n);
  for (int &x : u) {
    std::cin >> x;
    --x;
  }

  std::vector<int> s(n);
  for (int &x : s) {
    std::cin >> x;
  }

  std::vector<int> students(n);
  for (int i = 0; i < n; ++i) {
    students[i] = i;
  }

  auto cmp = [&](int a, int b) { return s[a] > s[b]; };
  std::sort(students.begin(), students.end(), cmp);

  std::vector<std::vector<i64>> universities(n);
  for (int student : students) {
    int university = u[student];
    int skill = s[student];
    universities[university].push_back(skill);
  }

  for (auto &university : universities) {
    int m = university.size();
    for (int i = 1; i < m; ++i) {
      university[i] += university[i - 1];
    }
  }

  std::vector<i64> result(n + 1);
  for (const auto &university : universities) {
    int m = university.size();
    for (int k = 1; k <= m; ++k) {
      int i = m - m % k - 1;
      result[k] += university[i];
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
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  while (T-- > 0) {
    solve();
  }

  return 0;
}
