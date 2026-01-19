#include <iostream>
#include <vector>

int roundUp(int x, int d) { return (x + d - 1) / d * d; }

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  if (k != 4) {
    int result = k;
    for (int x : a) {
      int rounded = roundUp(x, k);
      int distance = rounded - x;
      result = std::min(distance, result);
    }

    std::cout << result << '\n';
  } else {
    int nearestFour = 4;
    int firstNearestTwo = 2;
    int secondNearestTwo = 2;
    for (int x : a) {
      int roundedFour = roundUp(x, 4);
      int distanceFour = roundedFour - x;
      nearestFour = std::min(distanceFour, nearestFour);

      int roundedTwo = roundUp(x, 2);
      int distanceTwo = roundedTwo - x;
      if (distanceTwo < firstNearestTwo) {
        secondNearestTwo = firstNearestTwo;
        firstNearestTwo = distanceTwo;
      } else if (distanceTwo < secondNearestTwo) {
        secondNearestTwo = distanceTwo;
      }
    }

    int result = std::min(nearestFour, firstNearestTwo + secondNearestTwo);
    std::cout << result << '\n';
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
