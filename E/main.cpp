#include <bits/stdc++.h>

using namespace std;

void solve() {
  int e, t;
  cin >> e >> t;

  int k = -1;
  for (int i = 0; i < t; ++i) {
    int s = 0;
    for (int j = 0; j < e; ++j) {
      int x;
      cin >> x;
      s += x;
    }
    if (k == -1) {
      k = s;
    } else if (s != k) {
      k = -2;
    }
  }

  if (k < 0) {
    cout << "Maxwell daemon!\n";
  } else {
    cout << "Total energy is " << k << ", no physical law broken.\n";
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
  
  return 0;
}
