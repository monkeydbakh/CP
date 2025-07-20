#include <bits/stdc++.h>
#define int long long
#define task "task"
#define fi first
#define se second
using namespace std;

const int ma = 170, inf = 1e18;
int n, m, K;
int a[ma], c[ma][ma], dp[ma][ma][ma];

struct tmp {
  pair<int, int> best, second;
} t[ma];

void Read() {
  cin >> n >> m >> K;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> c[i][j];
  }
}

void solve() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int x = 1; x <= K; x++) dp[i][j][x] = inf;
    }
  }

  // nha 1
  if (a[1] != 0) dp[1][a[1]][1] = 0;
  else {
    for (int i = 1; i <= m; i++) {
      dp[1][i][1] = c[1][i];
    }
  }

  for (int i = 2; i <= n; i++) {
    // da son
    if (a[i] != 0) {
      for (int k = 1; k <= i; k++) {
        for (int j = 1; j <= m; j++) {
          if (j == a[i]) dp[i][a[i]][k] = min(dp[i][a[i]][k], dp[i - 1][a[i]][k]);
          else if (k > 1) dp[i][a[i]][k] = min(dp[i][a[i]][k], dp[i - 1][j][k - 1]);
        }
      }
      continue;
    }

    // reset
    for (int j = 1; j <= K; j++) {
      t[j].best.fi = t[j].second.fi = inf;
    }

    //tien xu li
    for (int j = 1; j <= m; j++) {
      for (int k = 1; k <= K; k++) {
        if (dp[i - 1][j][k] == inf) continue;

        if (dp[i - 1][j][k] < t[k].best.fi) {
          t[k].second = t[k].best;
          t[k].best.fi = dp[i - 1][j][k];
          t[k].best.se = j;
        } else if (dp[i - 1][j][k] < t[k].second.fi) {
          t[k].second.fi = dp[i - 1][j][k];
          t[k].second.se = j;
        }
      }
    }

    // chua son
    for (int j = 1; j <= m; j++) {
      for (int k = 1; k <= K; k++) {
        int C = c[i][j];

        if (dp[i - 1][j][k] != inf) {
          dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + C);
        }

        if (k > 1) {
          int tmp = t[k - 1].best.fi;
          if (j == t[k - 1].best.se) tmp = t[k - 1].second.fi;
          if (tmp != inf) dp[i][j][k] = min(dp[i][j][k], tmp + C);
        }
      }
    }
  }

  int res = inf;
  for (int i = 1; i <= m; i++) res = min(res, dp[n][i][K]);
  cout << (res != inf ? res : -1);
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

