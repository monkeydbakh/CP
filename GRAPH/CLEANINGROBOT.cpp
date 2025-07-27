#include <bits/stdc++.h>
#define int long long
#define task "task"
#define fi first
#define se second
using namespace std;

const int ma = 24, inf = 1e18;
int w, h, d[ma][ma], tmp = 0, dis[ma][ma], dp[1 << 11][ma], cnt = 0, st;
pair<char, int> a[ma][ma];
vector<pair<int, int>> point;
bool vis[ma][ma], used[404];

struct edge {
  int u, v, val;
};
vector<edge> e;

int x[] = {1, 0, -1, 0};
int y[] = {0, 1, 0, -1};

void reset() {
	for (int mask = 0; mask < (1 << 11); mask++) {
		for (int i = 0; i < ma; i++) dp[mask][i] = inf;
	}
	cnt = 0;
	memset(dis, -1, sizeof dis);
  memset(used, false, sizeof used);
  point.clear();
  e.clear();
  for (int i = 0; i < ma; i++) {
    for (int j = 0; j < ma; j++) a[i][j].fi = ' ', a[i][j].se = 0;
  }
}

void Read() {
  reset();
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j].fi;
      if (a[i][j].fi == 'o' || a[i][j].fi == '*') {
        point.push_back({i, j});
        a[i][j].se = cnt++;
				if (a[i][j].fi == 'o') st = a[i][j].se;
      }
      else a[i][j].se = -1;
    }
  }
}

void bfs(int u, int v, int f) {
  queue<pair<int, int>> q;
  memset(vis, false, sizeof vis);
  memset(d, 0, sizeof d);
  vis[u][v] = true;
  d[u][v] = 0;
  q.push({u, v});

  while (!q.empty()) {
    int i = q.front().fi, j = q.front().se;
    q.pop();
    for (int k = 0; k < 4; k++) {
      int nx = i + x[k], ny = j + y[k];
      if ((1 <= nx && nx <= h) && (1 <= ny && ny <= w) && !vis[nx][ny] && a[nx][ny].fi != 'x') {
        d[nx][ny] = d[i][j] + 1;
        if (a[nx][ny].se != -1) {
          int t = a[nx][ny].se;
          e.push_back({f, t, d[nx][ny]});
        }
        vis[nx][ny] = true;
        q.push({nx, ny});
      }
    }
  }
}

void solve() {
  memset(used, false, sizeof used);
  for (pair<int, int> it : point) {
    int u = it.fi, v = it.se;
    bfs(u, v, a[u][v].se);
  }

  for (edge it : e) {
		int u = it.u, v = it.v, val = it.val;
		dis[u][v] = val;
  }

  dp[(1 << st)][st] = 0;
  for (int mask = 0; mask < (1 << cnt); mask++) {
		for (int i = 0; i < cnt; i++) {
			if (!(mask >> i & 1)) continue;
			if (dp[mask][i] == inf) continue;
			for (int j = 0; j < cnt; j++) {
				if (mask >> j & 1) continue;
				int nmask = mask | (1 << j);
				if (dis[i][j] != -1) dp[nmask][j] = min(dp[mask][i] + dis[i][j], dp[nmask][j]);
			}
		}
  }

  int res = inf;
  for (int i = 0; i < cnt; i++) {
		res = min(res, dp[(1 << cnt) - 1][i]);
  }
  if (res != inf) cout << res << '\n';
  else cout << -1 << '\n';
}

signed main() {
  if(fopen(task ".inp", "r")) {
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> w >> h) {
    if (w == 0 && h == 0) return 0;
    Read();
    solve();
  }

  return 0;
}
