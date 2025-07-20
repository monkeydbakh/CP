#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

const int ma = 2004, INF = 1e18;
int n, pre[ma], dp[ma];
pair<int, int> a[ma];

void Read()
{
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i].se;
}

void solve()
{
  dp[0] = 0;
  for (int i = 1; i <= n; i++) dp[i] = INF;
  for (int i = 1; i <= n; i++)
  {
    int tmp = a[i].fi + 1;
    for (int j = n; j >= 0; j--)
    {
      if (dp[j] == INF) continue;
      int t = min(j + tmp, n);
      dp[t] = min(dp[t], dp[j] + a[i].se);
    }
  }

  cout << dp[n];
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  Read();
  solve();

  return 0;
}
