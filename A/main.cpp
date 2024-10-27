#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int a;
  int b;
  int t;
  int m;
  int c;
};

struct Objective {
  int t;
  int m;
  int c;
  int p;
  int pt;
  int pm;
  int pc;
};

class NonDominated {
public:
  vector<Objective> d;

  NonDominated() : d() {}

  void push(Objective o) {
    auto rend = remove_if(d.begin(), d.end(), [&](auto const& y) {
      return y.t >= o.t && y.m >= o.m && y.c >= o.c;
    });
    d.erase(rend, d.end());

    auto dominated = any_of(d.begin(), d.end(), [&](auto const& y) {
      return y.t <= o.t && y.m <= o.m && y.c <= o.c;
    });

    if (dominated) return;

    d.emplace_back(o);
  }
};

void solve() {
  int s, n;
  cin >> s >> n;

  int e = 0;

  vector<Edge> edges;

  for (int i = 0; i < n; i++) {
    int a, b, t, m, c;
    cin >> a >> b >> t >> m >> c;
    edges.emplace_back(Edge{a, b, t, m, c});
    e = max(e, max(a, b));
  }

  vector<NonDominated> d(e+1);
  d[s].push(Objective{0, 0, 0, 0});

  for(int i = 0; i <= e; ++i) {
    for (auto const& edge : edges) {
      for (auto const& nd : d[edge.a].d) {
        auto o = Objective{nd.t + edge.t, nd.m + edge.m, nd.c + edge.c, edge.a, nd.t, nd.m, nd.c};
        d[edge.b].push(o);
      }
    }
  }

  printf("Dest  Time Money   CO2 Prev  Time Money   CO2\n");
  for (int i = 1; i <= e; ++i) {
    sort(d[i].d.begin(), d[i].d.end(), [](auto const& lhs, auto const& rhs){
      return make_tuple(lhs.t, lhs.m, lhs.c) < make_tuple(rhs.t, rhs.m, rhs.c);
    });
    for (auto const& nd : d[i].d) {
      if (i == s) {
        printf("%4d%6d%6d%6d%5c%6d%6d%6d\n", s, 0, 0, 0, '-', 0, 0, 0);
      } else {
        printf("%4d%6d%6d%6d%5d%6d%6d%6d\n", i, nd.t, nd.m, nd.c, nd.p, nd.pt, nd.pm, nd.pc);
      }
    }
  }
}

int main() {
  solve();
  return 0;
}
