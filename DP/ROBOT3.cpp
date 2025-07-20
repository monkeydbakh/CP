#include <bits/stdc++.h>
#define int long long
#define task "task"
#define fi first
#define se second
using namespace std;

int n, m;

void Read() {
  cin >> n >> m;
}

void bfs(vector<vector<int>> &a, vector<vector<int>> &d) {
  queue<pair<int, int>> q;

  vector<int> R(m + 1, 1), D(n + 1, 1);
  d[1][1] = 1;
  q.push({1, 1});

  while (!q.empty()) {
    int x = q.front().fi, y = q.front().se;
    q.pop();

    int lim = min(n, x + a[x][y]);
    for (int nx = max(x + 1, R[y]); nx <= lim; nx++) {
      if (d[nx][y] == -1) {
        d[nx][y] = d[x][y] + 1;
        q.push({nx, y});
      }
    }
    R[y] = max(R[y], lim + 1);

    lim = min(m, y + a[x][y]);
    for (int ny = max(y + 1, D[x]); ny <= lim; ny++) {
      if (d[x][ny] == -1) {
        d[x][ny] = d[x][y] + 1;
        q.push({x, ny});
      }
    }
    D[x] = max(D[x], lim + 1);
  }
}

void solve() {
  vector<vector<int>> a(n + 1, vector<int> (m + 1));
  vector<vector<int>> d(n + 1, vector<int> (m + 1, -1));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  }

  bfs(a, d);
  cout << d[n][m];
}

signed main() {
  if(fopen(task ".inp", "r")) {
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Read();
  solve();

  return 0;
}

