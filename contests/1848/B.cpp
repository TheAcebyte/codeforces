#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<std::pair<int, int>> maxDistances(k, {-1, -1});
  std::vector<int> lastIndex(k, -1);
  for (int i = 0; i < n; ++i) {
    int c;
    std::cin >> c;
    --c;

    auto &distances = maxDistances[c];
    int distance = i - lastIndex[c] - 1;
    if (distance > distances.first) {
      distances.second = distances.first;
      distances.first = distance;
    } else if (distance > distances.second) {
      distances.second = distance;
    }

    lastIndex[c] = i;
  }

  for (int c = 0; c < k; ++c) {
    auto &distances = maxDistances[c];
    int distance = n - lastIndex[c] - 1;
    if (distance > distances.first) {
      distances.second = distances.first;
      distances.first = distance;
    } else if (distance > distances.second) {
      distances.second = distance;
    }
  }

  auto getDistance = [](const std::pair<int, int> &distances) {
    return std::max(distances.first / 2, distances.second);
  };

  int result = getDistance(maxDistances[0]);
  for (const auto &distances : maxDistances) {
    int distance = getDistance(distances);
    result = std::min(distance, result);
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
