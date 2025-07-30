#include <bits/stdc++.h>
#define int long long
#define task "task"
#define fi first
#define se second
using namespace std;

const int ma = 104, inf = 1e18;
int n, m, a[ma][ma], trace[ma][ma];
set<pair<int, int>> v;
map<pair<int, int>, int> mp;

void cal(int u, int e) {
	while (trace[e][u] != 0) {
		v.insert({e, trace[e][u]});
		e = trace[e][u];
	}
}

void Read() {
	for (int i = 0; i < ma; i++) {
		for (int j = 0; j < ma; j++) {
			if (i == j) a[i][j] = 0;
			else a[i][j] = inf;
		}
	}

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, val;
		cin >> u >> v >> val;
		if (a[u][v] > val) {
			a[u][v] = a[v][u] = val;
			trace[u][v] = v;
			trace[v][u] = u;
			mp[{u, v}] = i;
			mp[{v, u}] = i;
		}
	}
}

void solve() {
	for (int k = 1; k <= n; k++) {
		for (int u = 1; u <= n; u++) {
			for (int v = 1; v <= n; v++) {
				if (a[u][k] == inf || a[v][k] == inf) continue;
				if (a[u][v] > a[u][k] + a[k][v]) {
					a[u][v] = a[u][k] + a[k][v];
					trace[u][v] = trace[u][k];
				}
			}
		}
	}

	int res = inf, st;
	for (int i = 1; i <= n; i++) {
		if (a[i][1] == inf || a[i][2] == inf || a[i][3] == inf) continue;
		if (a[i][1] + a[i][2] + a[i][3] < res) {
			res = a[i][1] + a[i][2] + a[i][3];
			st = i;
		}
	}

	cout << res << '\n';
	cal(st, 1), cal(st, 2), cal(st, 3);
	cout << v.size() << '\n';
	for (auto it : v) {
		cout << mp[{it.fi, it.se}] << " ";
	}
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

