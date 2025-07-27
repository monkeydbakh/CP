#include <bits/stdc++.h>
#define int long long
#define task "task"
using namespace std;

const int ma = 21, mod = 1e9 + 7;
int n, a[ma][ma], dp[1 << ma][ma];

void Read() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> a[i][j];
  }
}

void solve() {
  for (int i = 0; i < n; i++) dp[1 << i][1] = (a[i][0] == 1 ? 1 : 0);
  for (int i = 1; i < n; i++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      if (dp[mask][i] == 0) continue;
      for (int j = 0; j < n; j++) {
        if (mask >> j & 1) continue;
        int nmask = mask | (1 << j);
        if (a[j][i]) dp[nmask][i + 1] = (dp[nmask][i + 1] + dp[mask][i]) % mod;
      }
    }
  }

  cout << dp[(1 << n) - 1][n];
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

