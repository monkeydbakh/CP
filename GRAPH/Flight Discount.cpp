#include <bits/stdc++.h>
#define int long long
#define task "task"
#define fi first
#define se second
using namespace std;

const int ma = 1e5 + 4, inf = 1e18;
int n, m;
vector<pair<int, int>> adj[ma], radj[ma];
vector<int> d1, d2;

struct edge {
  int u, v, val;
} a[ma * 2];

void Read() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, val;
    cin >> u >> v >> val;
    adj[u].push_back({v, val});
    radj[v].push_back({u, val});
    a[i] = {u, v, val};
  }
}

void dijkstra(int u, vector<int> &d, vector<pair<int, int>> adj[ma]) {
  d[u] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, u});
  while (!pq.empty()) {
    int u = pq.top().se, k = pq.top().fi;
    pq.pop();
    if (k > d[u]) continue;
    for (pair<int, int> it : adj[u]) {
      int v = it.fi, val = it.se;
      if (d[v] > d[u] + val) {
        d[v] = d[u] + val;
        pq.push({d[v], v});
      }
    }
  }
}

void solve() {
  d1.resize(n + 1, inf);
  d2.resize(n + 1, inf);
  dijkstra(1, d1, adj);
  dijkstra(n, d2, radj);

  int res = inf;
  for (int i = 1; i <= m; i++) {
    int u = a[i].u, v = a[i].v;
    res = min(res, d1[u] + d2[v] + (a[i].val / 2));
  }

  cout << res;
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

