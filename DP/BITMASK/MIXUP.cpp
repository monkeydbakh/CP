#include <bits/stdc++.h>
#define int long long
#define task "task"
using namespace std;

const int ma = 16;
int n, dp[(1 << 20)][ma], k, a[ma];

void Read() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < n; i++) dp[(1 << i)][i] = 1;
}

void solve() {
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int j = 0; j < n; j++) {
      if (!(mask >> j & 1)) continue;
      if (dp[mask][j] == 0) continue;
      for (int i = 0; i < n; i++) {
        if (mask >> i & 1) continue;
        int nmask = mask | (1 << i);
        if (abs(a[i] - a[j]) > k) dp[nmask][i] += dp[mask][j];
      }
    }
  }

  int res = 0;
  for (int i = 0; i < n; i++) res += (dp[(1 << n) - 1][i]);
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

