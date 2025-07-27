#include <bits/stdc++.h>
#define int long long
#define task "task"
#define fi first
#define se second
using namespace std;

const int ma = 2e5 + 4;
int n, m, k;
vector<pair<int, int>> adj[ma];
priority_queue<int> d[ma];

void Read() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int u, v, val;
    cin >> u >> v >> val;
    adj[u].push_back({v, val});
  }
}

void dijkstra() {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  d[1].push(0);
  pq.push({0, 1});

  while (!pq.empty()) {
    int c = pq.top().fi, u = pq.top().se;
    pq.pop();
    if (c > d[u].top()) continue;
    for (pair<int, int> it : adj[u]) {
      int v = it.fi, val = it.se;
      int nc = c + val;
      if (d[v].size() < k) {
        d[v].push(nc);
        pq.push({nc, v});
      } else if (d[v].top() > nc) {
        d[v].pop();
        d[v].push(nc);
        pq.push({nc, v});
      }
    }
  }
}

void solve() {
  dijkstra();
  priority_queue<int> &pq = d[n];
  stack<int> st;
  while (!pq.empty()) {
    st.push(pq.top());
    pq.pop();
  }

  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
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

