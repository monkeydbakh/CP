#include <bits/stdc++.h>
#define int long long
#define task "task"
using namespace std;

const int ma = 1e4 + 4;
int n, m, id[ma], low[ma], t = 0, res = 0;
vector<int> adj[ma];

void Read() {
  for (int i = 1; i <= n; i++) adj[i].clear();
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

void dfs(int u, int p) {
  id[u] = low[u] = ++t;
  int tmp = (p != -1);
  for (int v : adj[u]) {
    if (v == p) continue;
    if (id[v]) low[u] = min(low[u], id[v]);
    else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= id[u]) tmp++;
    }
  }

  res += (tmp >= 2);
}

void solve() {
  for (int i = 1; i <= n; i++) id[i] = low[i] = 0;
  res = t = 0;
  for (int i = 1; i <= n; i++) if (!id[i]) dfs(i, -1);
  cout << res << '\n';
}

signed main() {
  if(fopen(task ".inp", "r")) {
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n >> m) {
    if (n == 0 && m == 0) return 0;
    Read();
    solve();
  }

  return 0;
}


