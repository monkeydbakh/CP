#include <bits/stdc++.h>
#define int long long
#define task "task"
using namespace std;

const int ma = 2e3 + 4;
int n, m, cnt = 0;
vector<int> adj[ma];
bool vis[ma];

void Read() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
}

void dfs(int u) {
  vis[u] = true;
  for (int v : adj[u]) {
    if (!vis[v]) dfs(v);
  }
}

void solve() {
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cnt++;
      dfs(i);
    }
  }

  cout << m - n + cnt;
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

