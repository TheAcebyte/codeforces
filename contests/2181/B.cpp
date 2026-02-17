#include <iostream>
#include <queue>
#include <vector>

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> b(m);
  for (int &x : b) {
    std::cin >> x;
  }

  std::priority_queue<int> alice(a.begin(), a.end());
  std::priority_queue<int> bob(b.begin(), b.end());

  while (!alice.empty() && !bob.empty()) {
    int alice_attacker = alice.top();
    int bob_defender = bob.top();
    bob.pop();

    if (alice_attacker < bob_defender) {
      bob_defender -= alice_attacker;
      bob.push(bob_defender);
    }

    if (bob.empty()) {
      break;
    }

    alice.pop();
    int alice_defender = alice_attacker;
    int bob_attacker = bob.top();
    if (bob_attacker < alice_defender) {
      alice_defender -= bob_attacker;
      alice.push(alice_defender);
    }
  }

  if (alice.empty()) {
    std::cout << "Bob\n";
  } else {
    std::cout << "Alice\n";
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
