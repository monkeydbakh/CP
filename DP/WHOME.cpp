#include <bits/stdc++.h>
#define int long long
#define task "WHOME"
#define fi first
#define se second
using namespace std;

const int ma = 1e5 + 4;
int n, m, p, c, a[ma], s[10], dp[ma][100];

void Read()
{
	cin >> n >> m >> p >> c;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> s[i];
	sort(a + 1, a + 1 + n);
}

int cal(int l, int r)
{
	return p - (a[r] - a[l]) * (a[r] - a[l]) * c;
}

void solve()
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= 64; j++) dp[i][j] = -1e18;
	}
	
	dp[0][0] = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int mask = 0; mask < (1 << m); mask++)
		{
			if (dp[i][mask] == -1e18) continue;
			dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][mask]);
			for (int j = 1; j <= m; j++)
			{
				//if (mask >> (j - 1) & 1) continue;
				if (i + s[j] <= n)
					dp[i + s[j]][mask | (1 << (j - 1))] = max(dp[i + s[j]][mask | (1 << (j - 1))],
																										cal(i + 1, i + s[j]) + dp[i][mask]);
			}
		}
	}

	int res = LLONG_MIN;
	for (int i = m; i <= n; i++) res = max(res, dp[i][(1 << m) - 1]);
	cout << res;
}

signed main()
{
	if(fopen(task ".inp", "r"))
	{
		freopen(task ".inp", "r", stdin);
		freopen(task ".out", "w", stdout);
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Read();
	solve();

	return 0;
}
