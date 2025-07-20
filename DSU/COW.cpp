#include <bits/stdc++.h>
#define task "task"
#define int long long
using namespace std;

const int ma = 5e5 + 4;
int n, k, par[ma], sz[ma], s[ma], x, y;
string t;

int findpar(int u) {
  if (par[u] == u) return u;
  return findpar(par[u]);
}

void joint(int u, int v) {
  u = findpar(u), v = findpar(v);
  if (u == v) return;

  if (sz[u] < sz[v]) swap(u, v);
  par[v] = u;
  sz[u] += sz[v];
  s[v] -= s[u];
}

void add(int u, int val) {
  u = findpar(u);
  s[u] += val;
}

int get(int u) {
  int res = s[u];
  if (par[u] == u) return res;
  else return res + get(par[u]);
}

void solve() {
  while (k--) {
    cin >> t;
    if (t == "join" || t == "add") {
      cin >> x >> y;
      if (t == "join") joint(x, y);
      else add(x, y);
    } else {
      cin >> x;
      cout << get(x) << '\n';
    }
  }
}

signed main() {
	if(fopen(task ".inp", "r"))
	{
		freopen(task ".inp", "r", stdin);
		freopen(task ".out", "w", stdout);
	}
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1, s[i] = 0;
  solve();

  return 0;
}
