#include <iostream>
#include <map>
#include <set>

template<typename T>
void setmin(T& x, const T& y) {
  if (y < x) x = y;
}

void solve() {
  int n;
  std::cin >> n;

  std::map<int, int> frequency, total_operations;
  int x;
  std::cin >> x;
  std::set<int> seen;
  int operations = 0;
  while (seen.find(x) == seen.end()) {
    seen.insert(x);
    ++frequency[x];
    total_operations[x] += operations;
    if (x % 2 == 0) x /= 2;
    else ++x;
    ++operations;
  }

  for (int i = 0; i < n - 1; ++i) {
    int x;
    std::cin >> x;
    std::set<int> seen;
    int operations = 0;
    while (seen.find(x) == seen.end()) {
      seen.insert(x);
      if (frequency.find(x) != frequency.end()) {
        ++frequency[x];
        total_operations[x] += operations;
      }

      if (x % 2 == 0) x /= 2;
      else ++x;
      ++operations;
    }
  }

  int min_operations = total_operations[1];
  for (auto [x, f] : frequency) {
    if (f < n) continue;
    int operations = total_operations[x];
    setmin(min_operations, operations);
  }

  std::cout << min_operations << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
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
