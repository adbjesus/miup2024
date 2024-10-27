#include <bits/stdc++.h>

using namespace std;

int w, h;
int m;
vector<vector<int>> g;
vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

bool bfs(int x, int y, int c) {
  int z = 1;
  vector<pair<int, int>> q{{x, y}};
  vector<vector<bool>> vis(w, vector<bool>(h, false));
  vis[x][y] = true;

  while(!q.empty()) {
    auto [i, j] = q.back();
    q.pop_back();
    for (auto [dx,dy]: dirs) {
      auto nx = i+dx;
      auto ny = j+dy;
      if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
      if (g[nx][ny] == 1) continue;
      if (vis[nx][ny]) continue;
      q.emplace_back(nx, ny);
      vis[nx][ny] = true;
      z += 1;
    }
  }
  
  return c + z == m;
}

bool rec(int x, int y, int c) {
  if (c == m) return true;

  for (auto [dx,dy]: dirs) {
    auto nx = x+dx;
    auto ny = y+dy;
    if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
    if (g[nx][ny] == 1) continue;
    if (!bfs(nx, ny, c)) continue;
    g[nx][ny] = 1;
    if (rec(nx, ny, c+1)) return true;
    g[nx][ny] = 0;
  }
  
  return false;
}

void solve() {
  cin >> w >> h;
  m = w*h;
  int n;
  cin >> n;
  g.assign(w, vector<int>(h, 0));
  int posx, posy;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x][y] = 1;
    if (i == n-1) {
      posx = x;
      posy = y;
    }
  }

  if (rec(posx, posy, n)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}

int main() {
  solve();
  return 0;
}
