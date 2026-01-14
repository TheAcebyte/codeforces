#include <algorithm>
#include <iostream>
#include <vector>

struct Point {
  int x;
  int y;

  bool operator==(const Point &other) const {
    return x == other.x && y == other.y;
  }
};

std::vector<Point> generateKnightMoves(int a, int b) {
  if (a == b) {
    return {{-a, -a}, {-a, a}, {a, -a}, {a, a}};
  }

  return {
      {{-a, -b}, {-a, b}, {a, -b}, {a, b}, {-b, -a}, {b, -a}, {-b, a}, {b, a}}};
}

void solve() {
  int a, b, xk, yk, xq, yq;
  std::cin >> a >> b >> xk >> yk >> xq >> yq;

  auto moves = generateKnightMoves(a, b);
  std::vector<Point> kingStrikePositions;
  for (Point move : moves) {
    Point kingStrikePosition{xk + move.x, yk + move.y};
    kingStrikePositions.push_back(kingStrikePosition);
  }

  int result = 0;
  for (Point move : moves) {
    Point queenStrikePosition{xq + move.x, yq + move.y};
    auto it = std::find(kingStrikePositions.begin(), kingStrikePositions.end(),
                        queenStrikePosition);

    if (it != kingStrikePositions.end()) {
      ++result;
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

  int T;
  std::cin >> T;
  while (T-- > 0) {
    solve();
  }

  return 0;
}
