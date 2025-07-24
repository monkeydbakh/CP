#include <bits/stdc++.h>
#define int long long
#define task "task"
using namespace std;

const int ma = 304;
int n, p[ma][ma], cnt = 0;

struct edge {
  int u, v, val;
} a[100004];

struct disjoint_sets_union{
  int par[ma], sz[ma];

  void mem(int n) {
    for (int i = 0; i <= n; i++) {
      par[i] = i;
      sz[i] = 1;
    }
  }

  int findpar(int u) {
    if (par[u] == u) return u;
    return par[u] = findpar(par[u]);
  }

  bool join(int u, int v) {
    u = findpar(u);
    v = findpar(v);

    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
    return true;
  }
} dsu;

bool ss(edge a, edge b) {
  return a.val < b.val;
}

void Read() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[++cnt] = {0, i, x};
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cin >> p[i][j];
  }
}

void solve() {
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      a[++cnt] = {i, j, p[i][j]};
    }
  }

  sort(a + 1, a + 1 + cnt, ss);
  dsu.mem(n);
  int res = 0;
  for (int i = 1; i <= cnt; i++) {
    int u = a[i].u, v = a[i].v, val = a[i].val;
    if (dsu.join(u, v)) {
      res += val;
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

  Read();
  solve();

  return 0;
}

