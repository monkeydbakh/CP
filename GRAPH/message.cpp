#include <bits/stdc++.h>
#define int long long
#define task "task"
#define fi first
#define se second
using namespace std;

const int ma = 804;
int n, m, id[ma], low[ma], cnt = 0, scc = 0, mp[ma], in[ma];
vector<int> adj[ma];
stack<int> st;
bool vis[ma];
pair<int, int> edge[ma * ma];

void Read() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		edge[i] = {x, y};
	}
}

void dfs(int u) {
	id[u] = low[u] = ++cnt;
  st.push(u);
  for (int v : adj[u]) {
    if (vis[v]) continue;
    if (id[v]) low[u] = min(low[u], id[v]);
    else {
      dfs(v);
      low[u] = min(low[u], low[v]);
    }
  }

  if (id[u] == low[u]) {
    scc++;
    int v;
    do {
      v = st.top();
      mp[v] = scc;
      st.pop();
      vis[v] = true;
    } while (v != u);
  }
}

void solve() {
	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
	for (int i = 1; i <= m; i++) {
		int u = mp[edge[i].fi], v = mp[edge[i].se];
		if (u != v) in[v]++;
	}
	int res = 0;
	for (int i = 1; i <= scc; i++) res += (in[i] == 0);
	cout << res;
}

signed main() {
	if(fopen(task ".inp", "r")) {
		freopen(task ".inp", "r", stdin);
		freopen(task ".out", "w", stdout);
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Read();
	solve();

	return 0;
}

