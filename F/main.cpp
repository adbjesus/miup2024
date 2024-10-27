#include <bits/stdc++.h>

using namespace std;

int n;
int s;
int l;
vector<pair<int, int>> a;

pair<int, int> maxp = make_pair(numeric_limits<int>::max(), numeric_limits<int>::max());

vector<pair<int, int>> dp;

pair<int, int> rec(int i) {
  if (a[i].second == l) {
    return make_pair(0, 0);
  }

  if (dp[i] != maxp) return dp[i];
  
  auto ans = maxp;
  for (int j = i+1; j < n; ++j) {
    if (a[j].first <= a[i].second + 1) {
      auto aux = rec(j);
      auto aux2 = make_pair(aux.first + 1, aux.second + (a[i].second + 1 - a[j].first));
      ans = min(ans, aux2);
    }
  }
  
  return dp[i] = ans;
}

void solve() {
  cin >> n;
  a.assign(n, maxp);
  dp.assign(n, maxp);
  l = 0;
  s = numeric_limits<int>::max();
  
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
    s = min(s, a[i].first);
    l = max(l, a[i].second);
  }

  sort(a.begin(), a.end(), [](auto const& lhs, auto const& rhs) {
    return lhs.second < rhs.second;
  });

  pair<int, int> ans = make_pair(numeric_limits<int>::max(), numeric_limits<int>::max());
  for (int i = 0; i < n; ++i) {
    if (a[i].first == s) {
      auto aux = rec(i);
      ans = min(ans, aux);
    }
  }

  cout << ans.first+1 << " " << ans.second << "\n";
}

int main() {
  solve();
  return 0;
}
