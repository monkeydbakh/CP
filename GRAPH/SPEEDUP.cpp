#include <bits/stdc++.h>
#define int long long
#define task "task"
#define fi first
#define se second
using namespace std;

const int ma = 1004, inf = 1e18;
int n, m, K, mu[11];
double c, d[ma][14];
vector<pair<int, double>> adj[ma];

void mem() {
  mu[0] = 1;
  for (int i = 1; i <= 10; i++) mu[i] = mu[i - 1] * 2;
  for (int i = 0; i < ma; i++) {
    for (int j = 0; j < 14; j++) d[i][j] = inf;
  }
}

void Read() {
  cin >> n >> m >> K;
  for (int i = 1; i <= m; i++) {
    int u, v;
    double val;
    cin >> u >> v >> val;
    adj[u].push_back({v, val});
    adj[v].push_back({u, val});
  }
}

void dijkstra() {
  priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq;
  d[1][0] = 0;
  pq.push({0, {1, 0}});
  while (!pq.empty()) {
    double c = pq.top().fi;
    int u = pq.top().se.fi, k = pq.top().se.se;
    pq.pop();
    if (c > d[u][k]) continue;

    for (auto[v, w] : adj[u]) {
      for (int i = k; i <= K; i++) {
        int cnt = i - k;
        double nc = c + (w / mu[cnt]);
        if (nc < d[v][i]) {
          d[v][i] = nc;
          pq.push({nc, {v, i}});
        }
      }
    }
  }
}

void solve() {
  dijkstra();
  cout << fixed << setprecision(2) << d[n][K];
}

signed main() {
  if(fopen(task ".inp", "r")) {
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  mem();
  Read();
  solve();

  return 0;
}

