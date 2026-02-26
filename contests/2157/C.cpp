#include <iostream>
#include <vector>

struct query {
  int c;
  int l;
  int r;
};

void solve() {
  int n, k, q;
  std::cin >> n >> k >> q;

  std::vector<query> queries(q);
  for (auto &query : queries) {
    std::cin >> query.c >> query.l >> query.r;
    --query.l;
    --query.r;
  }

  std::vector<int> result(n);
  for (int i = 0; i < n; ++i) {
    bool overlap_with_type_one = false;
    bool overlap_with_type_two = false;
    for (const auto& query : queries) {
      if (i >= query.l && i <= query.r) {
        if (query.c == 1) {
          overlap_with_type_one = true;
        } else {
          overlap_with_type_two = true;
        }
      }
    }

    if (overlap_with_type_one && overlap_with_type_two) {
      result[i] = k + 1;
    } else if (overlap_with_type_one) {
      result[i] = k;
    } else {
      result[i] = i % k;
    }
  }

  const char *separator = "";
  for (int x : result) {
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
