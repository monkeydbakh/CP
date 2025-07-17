#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

const int ma = 1e5 + 4;
int dp[ma], n, t, cnt = 0;
pair<int, int> a[ma];
map<pair<int, int>, int> mp;

void Read()
{
  cin >> n >> t;
  for (int i = 1; i <= n; i++)
  {
    int x, y;
    cin >> x >> y;
    mp[{x, y}]++;
  }
}

void pre()
{
  for (pair<pair<int, int>, int> it : mp)
  {
    int tmp = 1;
    while (it.se >= tmp)
    {
      a[++cnt] = {tmp * it.fi.fi, tmp * it.fi.se};
      it.se -= tmp;
      tmp *= 2;
    }

    if (it.se > 0) a[++cnt] = {it.se * it.fi.fi, it.se * it.fi.se};
  }
}

void solve()
{
  pre();
  for (int i = 1; i <= cnt; i++)
  {
    for (int j = t; j >= 0; j--)
    {
      if (j - a[i].se >= 0) dp[j] = max(dp[j], dp[j - a[i].se] + a[i].fi);
    }
  }

  cout << dp[t];
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  Read();
  solve();

  return 0;
}
