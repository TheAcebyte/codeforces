#include <cstdint>
#include <iostream>

using u64 = std::uint64_t;

u64 findValue(int n, int row, int col) {
  int originRow = 0;
  int originCol = 0;
  u64 left = 1;
  u64 right = (u64)n * n;
  while (left < right) {
    n >>= 1;
    int middleRow = originRow + n;
    int middleCol = originCol + n;
    u64 start = left;
    u64 length = (right - left + 1) / 4;

    if (row <= middleRow && col <= middleCol) {
      left = start;
      right = start + length - 1;
    } else if (row > middleRow && col > middleCol) {
      originRow += n;
      originCol += n;
      left = start + length;
      right = start + 2 * length - 1;
    } else if (row <= middleRow && col > middleCol) {
      originCol += n;
      left = start + 3 * length;
      right = start + 4 * length - 1;
    } else if (row > middleRow && col <= middleCol) {
      originRow += n;
      left = start + 2 * length;
      right = start + 3 * length - 1;
    }
  }

  return left;
}

std::pair<int, int> findCell(int n, u64 d) {
  int row = 1;
  int col = 1;
  u64 left = 1;
  u64 right = (u64)n * n;
  while (left < right) {
    n >>= 1;
    u64 start = left;
    u64 length = (right - left + 1) / 4;
    if (d < start + length) {
      left = start;
      right = start + length - 1;
    } else if (d < start + 2 * length) {
      row += n;
      col += n;
      left = start + length;
      right = start + 2 * length - 1;
    } else if (d < start + 3 * length) {
      row += n;
      left = start + 2 * length;
      right = start + 3 * length - 1;
    } else {
      col += n;
      left = start + 3 * length;
      right = start + 4 * length - 1;
    }
  }

  return {row, col};
}

void solve() {
  int n, q;
  std::cin >> n >> q;

  int size = 1 << n;
  std::string type;
  while (q-- > 0) {
    std::cin >> type;
    if (type == "->") {
      int x, y;
      std::cin >> x >> y;
      u64 value = findValue(size, x, y);
      std::cout << value << '\n';
    } else {
      u64 d;
      std::cin >> d;
      auto cell = findCell(size, d);
      std::cout << cell.first << ' ' << cell.second << '\n';
    }
  }
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
