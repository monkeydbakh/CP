#include <bits/stdc++.h>
#define int long long
using namespace std;

const int ma = 204;
int n, m, a[ma][ma], dp[ma][ma][ma];
int y[3] = {-1, 0, 1}; 

void Read()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  }
}

void solve()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      for (int k = 1; k <= m; k++) dp[i][j][k] = LLONG_MIN;
    }
  }
  dp[1][1][m] = a[1][1] + a[1][m] - (m == 1) * a[1][1];

  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      for (int k = 1; k <= m; k++)
      {
        if (dp[i][j][k] == LLONG_MIN) continue;
        for (int d1 : y)
        {
          for (int d2 : y)
          {
            int nx = i + 1, ny1 = j + d1, ny2 = k + d2;
            if ((1 <= ny1 && ny1 <= m) && (1 <= ny2 && ny2 <= m))
              dp[nx][ny1][ny2] = max(dp[nx][ny1][ny2], dp[i][j][k] + a[nx][ny1] + a[nx][ny2] - (ny1  == ny2) * a[nx][ny1]);
          }
        }
      }
    }
  }

  int res = -1;
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      res = max(res, dp[n][i][j]);
    }
  }

  cout << res;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  Read();
  solve();

  return 0;
}
