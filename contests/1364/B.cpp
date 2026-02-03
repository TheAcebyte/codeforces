#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int& x : a) {
    std::cin >> x;
  }

  std::vector<int> subsequence;
  int i = 0;
  while (i < n - 1) {
    subsequence.push_back(a[i]);
    if (a[i + 1] >= a[i]) {
      while (i < n - 1 && a[i + 1] >= a[i]) {
        ++i;
      }
    } else {
      while (i < n - 1 && a[i + 1] <= a[i]) {
        ++i;
      }
    }
  }
  subsequence.push_back(a.back());

  int k = subsequence.size();
  std::cout << k << '\n';

  const char* separator = "";
  for (int x : subsequence) {
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
