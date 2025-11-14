#include <array>
#include <iostream>

void solve() {
  int n, q;
  std::cin >> n >> q;

  std::array<int, 51> indices;
  indices.fill(0);

  for (int i = 1; i <= n; ++i) {
    int color;
    std::cin >> color;

    if (indices[color] == 0) {
      indices[color] = i;
    }
  }

  const char *separator = "";
  for (int i = 0; i < q; ++i) {
    int color;
    std::cin >> color;

    for (int c = 1; c <= 50; ++c) {
      if (indices[c] < indices[color]) {
        ++indices[c];
      }
    }

    std::cout << separator << indices[color];
    indices[color] = 1;
    separator = " ";
  }
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
