#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

i64 inf = numeric_limits<i64>::min();

int v, e, n;
vector<i64> s;
i64 best = inf;
vector<vector<int>> g;
vector<int> u;
vector<int> o;
vector<int> ans;
vector<int> bans;

void rec(int i, int score) {
  if (i == v) {
    if (ans.size() == n) {
      if (score > best) {
        best = score;
        bans = ans;
      }
    }
    return;
  }

  // Use i
  if (u[o[i]] == 0) {
    for (auto j: g[o[i]]) u[j] += 1;
    ans.push_back(o[i]);
    rec(i+1, score+s[o[i]]);
    ans.pop_back();
    for (auto j: g[o[i]]) u[j] -= 1;
  }
  
  // Don't use i
  rec(i+1, score);
}

void solve() {
  cin >> v >> e >> n;

  s.assign(v, 0);
  o.assign(v, 0);
  u.assign(v, 0);

  for (int i = 0; i < v; ++i) {
    o[i] = i;
    i64 ct, pp, v;
    string x;
    cin >> ct >> pp >> v >> x;

    i64 b1 = count(x.begin(), x.end(), 'C');
    i64 b2 = count(x.begin(), x.end(), 'A');
    i64 b3 = count(x.begin(), x.end(), 'G');
    i64 b = b1*3 + b2*2 - b3;

    s[i] = ct*2 + pp + v + b;
  }

  g.assign(v, vector<int>());
  for (int i = 0; i < e; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  sort(o.begin(), o.end(), [&](int i, int j) {
    return s[i] > s[j];
  });

  for (int i = 0; i < v; ++i) {
    rec(i, 0);
  }

  if (best == inf) {
    cout << "IMPOSSIBLE\n";
  } else {
    sort(bans.begin(), bans.end());
    cout << bans[0];
    for (int i = 1; i < n; ++i) cout << " " << bans[i];
    cout << "\n";
  }
}

int main() {
  solve();
  
  return 0;
}
