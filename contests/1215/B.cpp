#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

template<typename I>
i64 sum(I begin, I end) {
  i64 result = 0;
  while (begin < end) {
    result += *begin;
    ++begin;
  }

  return result;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  int s = n;
  int t = n;
  std::vector<i64> positives(n);
  std::vector<i64> negatives(n);
  for (int i = n - 1; i >= 0; --i) {
    positives[i] += s - i;
    if (t < n) {
      positives[i] += negatives[t];
    }

    if (s < n) {
      negatives[i] += negatives[s];
    }

    if (a[i] < 0) {
      std::swap(positives[i], negatives[i]);
      t = s;
      s = i;
    }
  }

  i64 total_positives = sum(positives.begin(), positives.end());
  i64 total_negatives = sum(negatives.begin(), negatives.end());
  std::cout << total_negatives << ' ' << total_positives << '\n';
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
