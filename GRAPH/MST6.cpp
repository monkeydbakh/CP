#include <bits/stdc++.h>
#define int long long
#define task "task"
#define fi first
#define se second
using namespace std;

const int ma = 504, inf = 1e18;
int n, m, a[ma];
vector<pair<int, int>> adj[ma];
bool vis[ma];

void Read() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
}

int mu(int a, int b) {
  int res = 1;
  a %= m;
  while (b) {
    if (b % 2 == 1) res = (res * a) % m;
    a = (a * a) % m;
    b /= 2;
  }
  return res;
}
int cal(int i, int j) {
  int x = mu(a[i], a[j]);
  int y = mu(a[j], a[i]);
  return (x + y) % m;
}

void prim(int u) {
  vector<int> v;
  int res = 0;
  vis[u] = true;
  v.push_back(u);
  while (v.size() < n) {
    int Max = -inf;
    int p;
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) continue;
      for (pair<int, int> it : adj[i]) {
        int ver = it.fi, val = it.se;
        if (!vis[ver] && val > Max) {
          Max = val;
          p = ver;
        }
      }
    }

    v.push_back(p);
    res = res + Max;
    vis[p] = true;
  }

  cout << res;
}

void solve() {
  memset(vis, false, sizeof vis);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      adj[i].push_back({j, cal(i, j)});
    }
  }

  prim(1);
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

