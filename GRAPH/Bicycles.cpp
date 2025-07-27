#include <bits/stdc++.h>
#define int long long
#define task "task"
#define fi first
#define se second
using namespace std;

const int ma = 1004, inf = 1e18;
int n, m, d[ma][ma], a[ma];
vector<pair<int, int>> adj[ma];

void Read() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, val;
    cin >> u >> v >> val;
    adj[u].push_back({v, val});
    adj[v].push_back({u, val});
  }
  for (int i = 1; i <= n; i++) cin >> a[i];
}

void mem() {
  for (int i = 0; i < ma; i++) adj[i].clear();
  for (int i = 0; i < ma; i++) {
    for (int j = 0; j < ma; j++) d[i][j] = inf;
  }
}

void dijkstra() {
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
  d[1][1] = 0;
  pq.push({0, {1, 1}});
  while (!pq.empty()) {
    int c = pq.top().fi, u = pq.top().se.fi, k = pq.top().se.se;
    pq.pop();
    if (c > d[u][k]) continue;
    for (pair<int, int> it : adj[u]) {
      int v = it.fi, val = it.se;
      int nc = c + val * a[k];
      if (d[v][k] > nc) {
        d[v][k] = nc;
        pq.push({nc, {v, k}});
      }

      if (c < d[u][u]) {
        d[u][u] = c;
        pq.push({c, {u, u}});
      }
    }
  }
}

void solve() {
  dijkstra();
  int res = inf;
  for (int i = 1; i <= n; i++) res = min(res, d[n][i]);
  cout << res << '\n';
}

signed main() {
  if(fopen(task ".inp", "r")) {
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    mem();
    Read();
    solve();
  }

  return 0;
}

