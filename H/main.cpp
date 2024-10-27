#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> c(n, 0);
  vector<vector<int>> e(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    c[b] += 1;
    e[a].push_back(b);
  }

  priority_queue<pair<int, int>> q;
  for (int i = 0; i < n; ++i) {
    if (c[i] == 0) {
      q.emplace(0, -i);
    }
  }

  vector<int> ans;

  while(!q.empty()) {
    auto [o, a] = q.top();
    q.pop();
    a = -a;
    ans.push_back(a);

    for (auto b : e[a]) {
      c[b] -= 1;
      if (c[b] == 0) {
        q.emplace(o - 1, -b);
      }
    }
  }

  if (ans.size() != n) {
    cout << "IMPOSSIBLE\n";
  } else {
    cout << ans[0];
    for (int i = 1; i < n; ++i) cout << " " << ans[i];
    cout << "\n";
  }
}

int main() {
  solve();
  return 0;
}
