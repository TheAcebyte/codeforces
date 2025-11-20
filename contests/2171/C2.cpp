#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  int aScore = 0;
  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
    aScore ^= x;
  }

  int mScore = 0;
  std::vector<int> m(n);
  for (int &x : m) {
    std::cin >> x;
    mScore ^= x;
  }

  for (int i = 0; i < n; ++i) {
    if ((i % 2 == 0 && (aScore ^ a[i] ^ m[i]) >= (mScore ^ a[i] ^ m[i])) ||
        (i % 2 == 1 && (aScore ^ a[i] ^ m[i]) <= (mScore ^ a[i] ^ m[i]))) {
      aScore ^= a[i] ^ m[i];
      mScore ^= a[i] ^ m[i];
    }
  }

  if (aScore == mScore) {
    std::cout << "Tie\n";
  } else if (aScore > mScore) {
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
