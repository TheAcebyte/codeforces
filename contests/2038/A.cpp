#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> b(n);
  for (int &x : b) {
    std::cin >> x;
  }

  int total_work = 0;
  for (int i = 0; i < n; ++i) {
    total_work += a[i] / b[i];
  }

  if (total_work < k) {
    const char* separator = "";
    for (int i = 0; i < n; ++i) {
      std::cout << separator << 0;
      separator = " ";
    }
    std::cout << '\n';
    return;
  }

  const char* separator = "";
  for (int i = 0; i < n; ++i) {
    int work = a[i] / b[i];
    int reduced_work = std::min(work, total_work - k);
    work -= reduced_work;
    total_work -= reduced_work;

    std::cout << separator << work;
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
  solve();

  return 0;
}
