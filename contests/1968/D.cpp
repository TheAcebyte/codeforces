#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

void solve() {
  int n, k, b, s;
  std::cin >> n >> k >> b >> s;
  --b;
  --s;

  std::vector<int> p(n);
  for (int &x : p) {
    std::cin >> x;
    --x;
  }

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  u64 bodya = 0;
  u64 sasha = 0;
  u64 maxBodya = 0;
  u64 maxSasha = 0;
  int turns = std::min(n, k);
  for (int i = 0; i < turns; ++i, --k) {
    maxBodya = std::max(bodya + (u64)k * a[b], maxBodya);
    maxSasha = std::max(sasha + (u64)k * a[s], maxSasha);
    bodya += a[b];
    sasha += a[s];
    b = p[b];
    s = p[s];
  }

  if (maxBodya > maxSasha) {
    std::cout << "Bodya\n";
  } else if (maxBodya < maxSasha) {
    std::cout << "Sasha\n";
  } else {
    std::cout << "Draw\n";
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
