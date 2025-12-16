#include <iostream>
#include <vector>

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> left;
  std::vector<int> right;
  std::vector<int> p;
  p.reserve(n);

  int middle = (n + 1) / 2;
  int count = k / 2;
  int leftStep = middle / count;
  int rightStep = (n - middle) / count;
  int leftoverLeft = middle % count;
  int leftoverRight = (n - middle) % count;

  int l = middle;
  int r = middle + 1;
  while (l > 0 && r <= n) {
    p.push_back(l);
    p.push_back(r);

    r += rightStep;
    l -= leftStep;

    if (leftoverLeft > 0) {
      --l;
      --leftoverLeft;
    }

    if (leftoverRight > 0) {
      ++r;
      --leftoverRight;
    }
  }

  int i = 0;
  while (p.size() < n) {
    p.push_back(p[i] - 1);
    if (p.size() >= n) {
      break;
    }

    p.push_back(p[i + 1] + 1);
    i += 2;
  }

  const char *separator = "";
  for (int x : p) {
    std::cout << separator << x;
    separator = " ";
  }
  std::cout << '\n';
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
