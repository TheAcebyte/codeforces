#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

std::map<int, std::vector<int>> answers{
    {5, {2, 1, 3, 4, 5}}, {6, {2, 4, 5, 1, 3, 6}}, {7, {2, 4, 5, 1, 3, 6, 7}}};

int msb(int n) {
  int i = -1;
  while (n > 0) {
    n >>= 1;
    ++i;
  }

  return i;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> permutation;
  if (n <= 7) {
    permutation = answers[n];
  } else {
    permutation.reserve(n);
    std::vector<bool> taken(n + 1);
    auto take = [&](int x) {
      permutation.push_back(x);
      taken[x] = true;
    };

    int b = msb(n);
    take(n);
    if (n & 1) {
      take(1 << b);
    }
    take((1 << b) - 1);
    take((1 << b) - 2);
    take(3);
    take(1);

    for (int x = 1; x <= n; ++x) {
      if (!taken[x]) {
        permutation.push_back(x);
      }
    }

    std::reverse(permutation.begin(), permutation.end());
  }

  int k = 0;
  for (int i = 0; i < n; i += 2) {
    k &= permutation[i];
    if (i < n - 1) {
      k |= permutation[i + 1];
    }
  }

  std::cout << k << '\n';
  const char *separator = "";
  for (int x : permutation) {
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
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  while (T-- > 0) {
    solve();
  }

  return 0;
}
