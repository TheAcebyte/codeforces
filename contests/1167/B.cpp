#include <array>
#include <iostream>
#include <stdexcept>
#include <utility>

#define N 6

constexpr std::array<int, N> values{4, 8, 15, 16, 23, 42};

std::pair<int, int> find_product(int n) {
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      int x = values[i];
      int y = values[j];
      if (x * y == n) {
        return {x, y};
      }
    }
  }

  throw std::runtime_error("Could not find product.");
}

void solve() {
  int p1, p2, p3, p4;

  std::cout << "? 1 2" << std::endl;
  std::cin >> p1;

  std::cout << "? 2 3" << std::endl;
  std::cin >> p2;

  std::cout << "? 4 5" << std::endl;
  std::cin >> p3;

  std::cout << "? 5 6" << std::endl;
  std::cin >> p4;

  auto [a, b] = find_product(p1);
  auto [x1, y1] = find_product(p2);
  if (b != x1 && b != y1) {
    std::swap(a, b);
  }

  auto [e, f] = find_product(p4);
  auto [x2, y2] = find_product(p3);
  if (e != x2 && e != y2) {
    std::swap(e, f);
  }

  int c = b == x1 ? y1 : x1;
  int d = e == x2 ? y2 : x2;

  std::array<int, N> result{a, b, c, d, e, f};
  std::cout << '!';
  for (int x : result) {
    std::cout << ' ' << x;
  }
  std::cout << std::endl;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  solve();

  return 0;
}
