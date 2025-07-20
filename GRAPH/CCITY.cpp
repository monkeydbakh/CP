#include <bits/stdc++.h>
#define int long long
#define task "task"
#define fi first
#define se second
using namespace std;

const int ma = 2e5 + 4;
int n, m, cnt = 0, id[ma], deg[ma];
pair<int, int> edge[ma];
vector<int> adj[ma], adj1[ma], v, sccid[ma];
bool vis[ma];
stack<int> st;
set<pair<int, int>> s;

void Read() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		edge[i] = {u, v};
		adj[u].push_back(v);
		adj1[v].push_back(u);
	}
}

// dfs lan 1
void dfs(int u) {
	vis[u] = true;
	for (int v : adj[u]) {
		if (!vis[v]) dfs(v);
	}
	st.push(u);
}

// dfs do thi dao
void dfs1(int u) {
	vis[u] = true;
	sccid[cnt].push_back(u); // ds dinh thuoc tpltm thu cnt
	id[u] = cnt; // u thuoc tpltm thu cnt
	for (int v : adj1[u]) {
		if (!vis[v]) {
			dfs1(v);
		}
	}
}

void cal() {
	for (int i = 1; i <= m; i++) {
		int u = id[edge[i].fi], v = id[edge[i].se];
		if (u != v && s.find({u, v}) == s.end()) {
			deg[u]++;
			s.insert({u, v});
		}
	}

	for (int i = 1; i <= cnt; i++) {
		if (deg[i] == 0) {
			for (int d : sccid[i]) v.push_back(d);
		}
	}
}

void solve() {
	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
	memset(vis, false, sizeof vis);
	while (!st.empty()) {
		int k = st.top();
		st.pop();
		if (!vis[k]) {
			cnt++;
			dfs1(k);
		}
	}
	cal();
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int d : v) cout << d << " ";
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

