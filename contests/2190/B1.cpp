#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  std::vector<int> nearest_opening(n);
  nearest_opening[n - 1] = n;
  for (int i = n - 2; i >= 0; --i) {
    if (s[i] == '(') {
      nearest_opening[i] = i;
    } else {
      nearest_opening[i] = nearest_opening[i + 1];
    }
  }

  std::vector<int> suffix_openings(n + 1);
  for (int i = n - 1; i >= 0; --i) {
    suffix_openings[i] = suffix_openings[i + 1];
    if (s[i] == '(') {
      ++suffix_openings[i];
    }
  }

  std::vector<int> suffix_balance(n + 1);
  for (int i = n - 1; i >= 0; --i) {
    suffix_balance[i] = suffix_balance[i + 1];
    if (s[i] == '(') {
      ++suffix_balance[i];
    } else {
      --suffix_balance[i];
    }
  }

  int result = -1;
  int balance = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      ++balance;
    } else {
      --balance;
    }

    if (s[i] == '(') {
      continue;
    }

    int j = nearest_opening[i];
    if (j >= n) {
      continue;
    }

    int deleted_openings = balance + 1 + suffix_balance[j];
    if (suffix_openings[j] > deleted_openings) {
      int length = i + n - j - deleted_openings;
      result = std::max(length, result);
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
