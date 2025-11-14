#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> evens;
  std::vector<int> odds;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    if (x & 1) {
      odds.push_back(x);
    } else {
      evens.push_back(x);
    }
  }

  auto cmp = std::greater<int>();
  std::sort(evens.begin(), evens.end(), cmp);
  std::sort(odds.begin(), odds.end(), cmp);

  int a = evens.size();
  int b = odds.size();
  int i = 0;
  int j = 0;
  u64 alice = 0;
  u64 bob = 0;

  bool turn = true;
  while (i < a || j < b) {
    if (turn) {
      if ((i < a && j < b && evens[i] > odds[j]) || (i < a && j >= b)) {
        alice += evens[i++];
      } else {
        ++j;
      }
    } else {
      if ((i < a && j < b && evens[i] <= odds[j]) || (i >= a && j < b)) {
        bob += odds[j++];
      } else {
        ++i;
      }
    }

    turn = !turn;
  }

  if (alice == bob) {
    std::cout << "Tie\n";
  } else if (alice > bob) {
    std::cout << "Alice\n";
  } else {
    std::cout << "Bob\n";
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
