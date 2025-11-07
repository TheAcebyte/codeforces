#include <array>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }

    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> b[i];
    }

    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> c[i];
    }

    std::array<int, 3> aMax{-1, -1 -1}; 
    std::array<int, 3> bMax{-1, -1 -1}; 
    std::array<int, 3> cMax{-1, -1 -1}; 
    for (int k = 0; k < 3; ++k) {
      int ai = -1;
      int bi = -1;
      int ci = -1;
      for (int j = 0; j < n; ++j) {
        if (ai == -1) {
          ai = a[j];
        }
      }
    }
  }

  return 0;
}
