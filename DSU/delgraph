#include <bits/stdc++.h>
#define itn long long
#define fi first
#define se second
using namespace std;

const int ma = 150004;
int n, m, par[ma], sz[ma], k;
string res[ma];

struct queries{
  string k;
  int u, v;
} a[ma];

int findpar(int u) {
  if (par[u] == u) return u;
  return par[u] = findpar(par[u]);
}

void joint(int u, int v) {
  u = findpar(u);
  v = findpar(v);

  if (sz[u] < sz[v]) swap(u, v);
  par[v] = par[u];
  sz[u] += sz[v];
}

void Read() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
  }
  for (int i = 1; i <= k; i++) cin >> a[i].k >> a[i].u >> a[i].v;
  for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
}

void solve() {
  for (int i = k; i >= 1; i--) {
    if (a[i].k == "ask") {
      res[i] = (findpar(a[i].u) == findpar(a[i].v) ? "YES" : "NO");
    } else {
      if (findpar(a[i].u) != findpar(a[i].v)) joint(a[i].u, a[i].v);
    }
  }

  for (int i = 1; i <= k; i++) if (res[i] != "") cout << res[i] << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Read();
  solve();

  return 0;
}
