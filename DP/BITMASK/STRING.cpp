#include <bits/stdc++.h>
#define int long long
#define task "task"
using namespace std;

const int inf = 1e18;
int n;
string s;
int dp[(1 << 20) + 4];

void Read() {
  cin >> n >> s;
}

void solve() {
  int tmp = 0;
  for (int i = 0; i < n; i++) {
    tmp |= ((s[i] - 'A') << i);
  }

  for (int i = 0; i < (1 << n); i++) dp[i] = inf;
  dp[tmp] = 0;
  queue<int> q;
  q.push(tmp);

  while (!q.empty()) {
    int mask = q.front();
    q.pop();

    for (int i = 0; i < n - 1; i++) {
      int nmask = mask ^ (1 << i) ^ (1 << (i + 1));
      if (dp[nmask] == inf) {
        dp[nmask] = dp[mask] + 1;
        q.push(nmask);
      }
    }

    for (int i = 0; i < n - 2; i++) {
      int nmask = mask ^ (1 << i) ^ (1 << (i + 1)) ^ (1 << (i + 2));
      if (dp[nmask] == inf) {
        dp[nmask] = dp[mask] + 1;
        q.push(nmask);
      }
    }
  }

  cout << min(dp[0], dp[(1 << n) - 1]);
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

