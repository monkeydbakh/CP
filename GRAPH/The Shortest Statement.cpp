#include <bits/stdc++.h>
#define int long long
#define task "task"
#define fi first
#define se second
using namespace std;

const int ma = 1e5 + 4, inf = 1e18;
int n, m, d[ma];

struct edge {
  int u, v, val;
} a[ma];
vector<pair<int, int>> adj[ma], adj2[ma];
vector<int> vec;
vector<edge> ex;
map<int, vector<int>> mp;

void Read() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].u >> a[i].v >> a[i].val;
  }
}

struct disjoint_sets_union {
  int par[ma], sz[ma];
  void mem(int n) {
    for (int i = 1; i <= n; i++) {
      par[i] = i;
      sz[i] = 1;
    }
  }

  int findpar(int u) {
    if (u == par[u]) return u;
    return par[u] = findpar(par[u]);
  }

  bool join(int u, int v) {
    u = findpar(u), v = findpar(v);
    if (u == v) return false;

    par[v] = u;
    sz[u] += sz[v];
    return true;
  }
} dsu;

struct LCA {
  int up[ma][20], h[ma];

  void dfs(int u) {
    for (auto &[v, w] : adj2[u]) {
      if (v == up[u][0]) continue;

      d[v] = d[u] + w;
      h[v] = h[u] + 1;
      up[v][0] = u;
      for (int i = 1; i <= 17; i++) up[v][i] = up[up[v][i - 1]][i - 1];
      dfs(v);
    }
  }

  int f(int u, int v) {
    if (h[u] != h[v]) {
      if (h[u] < h[v]) swap(u, v);
      int k = h[u] - h[v];
      for (int i = 0; (1 << i) <= k; i++) {
        if (k >> i & 1) u = up[u][i];
      }
    }

    if (u == v) return u;
    int k = __lg(h[u]);
    for (int i = k; i >= 0; i--) {
      if (up[u][i] != up[v][i]) {
        u = up[u][i], v = up[v][i];
      }
    }

    return up[u][0];
  }

  int cal(int u, int v) {
    int t = f(u, v);
    return d[u] + d[v] - 2 * d[t];
  }
} lca;

void dijkstra(int u) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  vector<int> d(n + 1, inf);
  d[u] = 0;
  pq.push({0, u});
  while (!pq.empty()) {
    int u = pq.top().se, k = pq.top().fi;
    pq.pop();
    if (k > d[u]) continue;

    for (pair<int, int> it : adj[u]) {
      auto [v, c] = it;
      int nc = k + c;
      if (d[v] > nc) {
        d[v] = nc;
        pq.push({nc, v});
      }
    }
  }

  mp[u] = d;
}

void solve() {
  dsu.mem(n);
  for (int i = 1; i <= m; i++) {
    int u = a[i].u, v = a[i].v, val = a[i].val;
    adj[u].push_back({v, val});
    adj[v].push_back({u, val});
    if (dsu.join(u, v)) {
      adj2[u].push_back({v, val});
      adj2[v].push_back({u, val});
    } else {
      vec.push_back(u);
      vec.push_back(v);
      ex.push_back(a[i]);
    }
  }

  lca.dfs(1);
  sort(vec.begin(), vec.end());
  auto tmp = unique(vec.begin(), vec.end());
  vec.erase(tmp, vec.end());
  for (int u : vec) dijkstra(u);
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    int res = lca.cal(u, v);
    for (edge e : ex) {
      int x = e.u, y = e.v, val = e.val;
      res = min({res,
                mp[x][u] + mp[y][v] + val,
                mp[y][u] + mp[x][v] + val});
    }
    cout << res << '\n';
  }
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

