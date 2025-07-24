#include <bits/stdc++.h>
#define task "task"
#define fi first
#define se second
using namespace std;

const int ma = 1e5 + 4;
int n, res = 0;
pair<int, int> x[ma], y[ma], z[ma];
map<pair<int, int>, int> mp;

struct edge
{
	int u, v, w;
};

struct disjoint_sets_union {
	int par[ma], sz[ma];
	void mem(int n) {
		for (int i = 1; i <= n; i++) {
			par[i] = i;
			sz[i] = 1;
		}
	}

	int findpar(int u) {
		if (par[u] == u) return u;
		return par[u] = findpar(par[u]);
	}

	void join(int u, int v, int val) {
		u = findpar(u);
		v = findpar(v);

		if (u == v) return;
		if (sz[u] < sz[v]) swap(u, v);
		res += val;
		par[v] = u;
		sz[u] += sz[v];
	}
} dsu;

auto cmp = [](const edge &a, const edge &b) {
    return a.w > b.w;
};
priority_queue<edge, vector<edge>, decltype(cmp)> pq(cmp);

void Read() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i].fi >> y[i].fi >> z[i].fi;
		x[i].se = y[i].se = z[i].se = i;
	}
}

void solve() {
	// x
	sort(x + 1, x + 1 + n);
	for (int i = 1; i < n; i++) {
		int u = x[i].se, v = x[i + 1].se;
		int c = x[i + 1].fi - x[i].fi;
		if (mp.find({u, v}) == mp.end()) mp[{u, v}] = c;
		else mp[{u, v}] = min(mp[{u, v}], c);
	}

	// y
	sort(y + 1, y + 1 + n);
	for (int i = 1; i < n; i++) {
		int u = y[i].se, v = y[i + 1].se;
		int c = y[i + 1].fi - y[i].fi;
		if (mp.find({u, v}) == mp.end()) mp[{u, v}] = c;
		else mp[{u, v}] = min(mp[{u, v}], c);
	}

	// z
	sort(z + 1, z + 1 + n);
	for (int i = 1; i < n; i++) {
		int u = z[i].se, v = z[i + 1].se;
		int c = z[i + 1].fi - z[i].fi;
		if (mp.find({u, v}) == mp.end()) mp[{u, v}] = c;
		else mp[{u, v}] = min(mp[{u, v}], c);
	}

	dsu.mem(n);
	for (auto it : mp) {
		pq.push({it.fi.fi, it.fi.se, it.se});
	}

	while (!pq.empty()) {
		int u = pq.top().u, v = pq.top().v, w = pq.top().w;
		pq.pop();
		if (dsu.findpar(u) != dsu.findpar(v)) {
			dsu.join(u, v, w);
		}
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
	cout.tie(NULL);

	Read();
	solve();

	return 0;
}

