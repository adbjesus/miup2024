#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  int e;
  cin >> e;

  unordered_map<int, int> p;
  unordered_map<int, int> s;
  unordered_map<int, int> id;

  vector<int> root(n, 0);
  vector<int> counta(n, 0);

  auto fin = [&](int a) {
    auto r = p[a];
    while(p[r] != r) r = p[r];

    while(a != r) {
      int b = p[a];
      p[a] = r;
      a = b;
    }

    return r;
  };

  // a node
  // b root of component
  auto uni = [&](int a, int b) {
    int ra = fin(a);
    int rb = fin(b);

    if (ra == rb) return;

    // They belong to different components
    // We still count it towards the current component
    counta[id[rb]] += 1;

    auto ca = counta[id[ra]];
    auto cb = counta[id[rb]];
    auto ida = id[ra];
    auto idb = id[rb];

    // cerr << ca << " " << cb << " " << ida << " " << idb << "\n";

    if (ca > cb || (ca == cb && ida < idb)) {
      p[rb] = ra;
      s[ra] += s[rb];
      counta[id[ra]] = s[ra];
    } else {
      p[ra] = rb;
      s[rb] += s[ra];
      counta[id[rb]] = s[rb];
    }
  };

  for (int i = 0; i < e; ++i) {
    int c, x, y, z;
    cin >> c >> x >> y >> z;

    int v = x + y*100 + z*100*100;

    // New component let's initialize it
    if (counta[c] == 0) {
      counta[c] = 1;
      root[c] = v;
      if (id.find(v) != id.end()) {
        auto rv = fin(v);
        auto c2 = id[rv];
        if (counta[c2] == 1 && c < c2) {
          id[rv] = c;
        }
      }
    }

    // New node, let's initialize it
    if (id.find(v) == id.end()) {
      id[v] = c;
      p[v] = v;
      s[v] = 1;
    }

    uni(v, root[c]);
  }

  for (auto c : counta) {
    cout << c << "\n";
  }
}

int main() {
  solve();
  
  return 0;
}
