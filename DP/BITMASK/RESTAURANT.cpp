#include <bits/stdc++.h>
#define int long long
#define task "task"
using namespace std;

const int ma = 20;
map<pair<int, int>, int> mp;
int n, m, k, dp[(1 << ma)][ma], a[ma];

void Read() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < k; i++) {
    int x, y, val;
    cin >> x >> y >> val;
    mp[{--x, --y}] = val;
  }

  memset(dp, 0, sizeof dp);
  for (int i = 0; i < n; i++) dp[(1 << i)][i] = a[i];
}

void solve() {
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if (!(mask >> i & 1)) continue;
      for (int j = 0; j < n; j++) {
        if (mask >> j & 1) continue;
        int nmask = mask | (1 << j);
        int val = a[j];
        auto it = mp.find({i, j});
        if (it != mp.end()) val += it->second;
        dp[nmask][j] = max(dp[nmask][j], dp[mask][i] + val);
      }
    }
  }

  int res = -1;
  for (int mask = 0; mask < (1 << n); mask++) {
    if (__builtin_popcount(mask) != m) continue;
    for (int i = 0; i < n; i++) res = max(res, dp[mask][i]);
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

