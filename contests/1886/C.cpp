#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using i64 = std::int64_t;

void solve() {
  std::string s;
  i64 p;
  std::cin >> s >> p;
  int n = s.length();
  --p;

  std::vector<bool> deleted(n);
  std::vector<int> last_undeleted(n, -1);
  int current_length = n;

  auto get_ith_character = [&](int i) -> char {
    int j = -1;
    for (int k = 0; k < n; ++k) {
      j += !deleted[k];
      if (j == i) {
        return s[k];
      }
    }

    return -1;
  };

  auto delete_and_check = [&](int i) {
    deleted[i] = true;
    p -= current_length--;

    if (p >= current_length) {
      return false;
    }

    return true;
  };

  if (p < n) {
    std::cout << get_ith_character(p);
    return;
  }

  int i = 0;
  while (i < n) {
    while (i < n - 1 && s[i] <= s[i + 1]) {
      last_undeleted[i + 1] = i;
      ++i;
    }

    if (i >= n - 1) {
      break;
    }

    if (delete_and_check(i)) {
      std::cout << get_ith_character(p);
      return;
    }

    int j = last_undeleted[i++];
    while (j >= 0 && s[j] > s[i]) {
      if (delete_and_check(j)) {
        std::cout << get_ith_character(p);
        return;
      }

      j = last_undeleted[j];
    }

    last_undeleted[i] = j;
  }

  while (i >= 0) {
    if (delete_and_check(i)) {
      std::cout << get_ith_character(p);
      return;
    }

    i = last_undeleted[i];
  }
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

  std::cout << '\n';
  return 0;
}
