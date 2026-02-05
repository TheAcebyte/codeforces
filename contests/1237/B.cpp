#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
    --x;
  }

  std::vector<int> b(n);
  for (int &x : b) {
    std::cin >> x;
    --x;
  }

  std::vector<bool> seen(n);
  int i = 0;
  int j = 0;
  int result = 0;
  while (j < n) {
    if (seen[a[i]]) {
      ++i;
    } else if (b[j] == a[i]) {
      ++i;
      ++j;
    } else {
      seen[b[j]] = true;
      ++result;
      ++j;
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
  solve();

  return 0;
}
