#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> spendings(n);
  for (int &spending : spendings) {
    std::cin >> spending;
  }

  std::vector<int> budgets(n);
  for (int &budget : budgets) {
    std::cin >> budget;
  }

  std::vector<int> remaining(n);
  for (int i = 0; i < n; ++i) {
    remaining[i] = budgets[i] - spendings[i];
  }
  std::sort(remaining.begin(), remaining.end());

  int result = 0;
  int left = 0;
  int right = n - 1;
  while (left < right) {
    if (remaining[left] + remaining[right] >= 0) {
      ++result;
      ++left;
      --right;
    } else {
      ++left;
    }
  }

  std::cout << result << '\n';
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
