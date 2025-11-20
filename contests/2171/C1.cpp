#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> m(n);
  for (int &x : m) {
    std::cin >> x;
  }

  int aScore = 0;
  int mScore = 0;
  int aSwap = -1;
  int mSwap = -1;

  for (int i = 0; i < n; ++i) {
    aScore ^= a[i];
    mScore ^= m[i];

    if (a[i] != m[i]) {
      if (i & 1) {
        mSwap = i;
      } else {
        aSwap = i;
      }
    }
  }

  if (aScore == mScore) {
    std::cout << "Tie\n";
  } else if (aSwap == -1 && mSwap == -1) {
    if (aScore > mScore) {
      std::cout << "Ajisai\n";
    } else {
      std::cout << "Mai\n";
    }
  } else if (aSwap > mSwap) {
    std::cout << "Ajisai\n";
  } else {
    std::cout << "Mai\n";
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
