#include <bits/stdc++.h>
#define int long long
#define task "task"
#define fi first
#define se second
using namespace std;

const int ma = 2e5 + 4;
set<int> cont[ma];
char k;
int u, v, par[ma], n, q;

void Read() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cont[i].insert(x);
		par[i] = i;
	}
}

int findpar(int u) {
	if (par[u] == u) return u;
	return par[u] = findpar(par[u]);
}

void joint(int u, int v) {
	u = findpar(u), v = findpar(v);
	if (u == v) return;

	if (cont[u].size() < cont[v].size()) swap(u, v);
	for (int d : cont[v]) {
		cont[u].insert(d);
	}
	cont[v].clear();
	par[v] = u;
}

int f(int u, int x) {
	u = findpar(u);
	auto it = cont[u].lower_bound(x);
	if (it == cont[u].end()) return -1;
	else return *it;
}

void solve() {
	while (q--) {
		cin >> k >> u >> v;
		if (k == '~') joint(u, v);
		else cout << f(u, v) << '\n';
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
