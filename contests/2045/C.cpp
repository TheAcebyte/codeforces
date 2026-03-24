#include <array>
#include <iostream>
#include <string>

void solve() {
  std::string s, t;
  std::cin >> s >> t;
  int n = s.length();
  int m = t.length();

  std::array<int, 26> leftmost_letters_s;
  leftmost_letters_s.fill(-1);
  for (int i = 1; i < n; ++i) {
    int l = s[i] - 'a';
    if (leftmost_letters_s[l] == -1) {
      leftmost_letters_s[l] = i;
    }
  }

  std::array<int, 26> rightmost_letters_t;
  rightmost_letters_t.fill(-1);
  for (int j = m - 2; j >= 0; --j) {
    int l = t[j] - 'a';
    if (rightmost_letters_t[l] == -1) {
      rightmost_letters_t[l] = j;
    }
  }

  auto abv_length = [m](int i, int j) { return i + m - j - 1; };
  int i = n;
  int j = -1;
  for (char l = 0; l < 26; ++l) {
    if (leftmost_letters_s[l] == -1 || rightmost_letters_t[l] == -1) {
      continue;
    }

    int new_i = leftmost_letters_s[l];
    int new_j = rightmost_letters_t[l];
    int old_abv_length = abv_length(i, j);
    int new_abv_length = abv_length(new_i, new_j);
    if (new_abv_length < old_abv_length) {
      i = new_i;
      j = new_j;
    }
  }

  if (i == n && j == -1) {
    std::cout << -1 << '\n';
    return;
  }

  std::string result = s.substr(0, i) + t.substr(j, m - j);
  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  solve();

  return 0;
}
