#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

void solve() {
  i64 n, k;
  cin >> n >> k;

  i64 l = 1;
  i64 r = 0;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    r += v[i];
  }

  while(l < r) {
    i64 m = l + (r-l+1)/2;

    bool possible = false;
    for (i64 i = 0; i < n; ++i) {
      i64 z = i;
      for (int j = 0; j < k && z <= i+n; ++j) {
        i64 s = 0;
        while (s < m) {
          s += v[z % n];
          z += 1;
        }
      }
      if (z <= i + n) {
        // Possible
        l = m;
        possible = true;
        break;
      }
    }

    if (!possible) {
      r = m - 1;
    }
  }

  cout << l << "\n";
}

int main() {
  solve();
  return 0;
}
