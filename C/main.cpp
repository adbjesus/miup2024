#include <bits/stdc++.h>

using namespace std;

// Gale-Shapley algorithm
// Preferences should use 0-base indexing
// Data should be balanced
vector<int> gale_shapley(vector<vector<int>> const& left_prefs, vector<vector<int>> const& right_prefs) {
  int n = left_prefs.size();
  vector<int> left_matches(n, -1);
  vector<int> right_matches(n, -1);
  vector<int> left_proposals(n, 0);
  vector<vector<int>> right_proposals(n, vector<int>(n, 0));
  vector<map<int, int>> right_rankings(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      right_rankings[i][right_prefs[i][j]] = j;
    }
  }

  int count = n;
  while (count > 0) {
    int left;
    for (left = 0; left < n; ++left) {
      if (left_matches[left] == -1) {
        break;
      }
    }

    int right;
    for (int i = 0; i < n && left_matches[left] == -1; ++i) {
      right = left_prefs[left][i];
      if (!right_proposals[right][left]) {
        right_proposals[right][left] = 1;
        left_proposals[left]++;
        if (right_matches[right] == -1) {
          left_matches[left] = right;
          right_matches[right] = left;
          count--;
        }
        else {
          if (right_rankings[right][left] < right_rankings[right][right_matches[right]]) {
            int prev_left = right_matches[right];
            left_matches[prev_left] = -1;
            left_matches[left] = right;
            right_matches[right] = left;
          }
        }
      }
    }
  }

  return left_matches;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(m, vector<int>(m));
  vector<vector<int>> b(m, vector<int>(m));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      a[i][j] -= 1;
    }
  }
  // Dummy
  for (int i = n; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      a[i][j] = j;
    }
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> b[i][j];
      b[i][j] -= 1;
    }
    for (int j = n; j < m; ++j) {
      b[i][j] = j;
    }
  }

  auto ans = gale_shapley(a, b);
  for (int i = 0; i < n; ++i) {
    cout << ans[i]+1 << "\n";
  }
}

int main() {
  solve();
  return 0;
}
