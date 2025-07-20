#include <bits/stdc++.h>
#define int long long
#define task "task"
#define fi first
#define se second
using namespace std;

const int ma = 204;
int n, m, a[ma][ma], dp[2 * ma][ma][ma];
pair<int, int> d[2] = {{0, 1}, {1, 0}};

void Read(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	}
}

void mem(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			for (int k = 1; k <= m; k++) dp[i][j][k] = -1;
		}
	}
}

void solve(){
	mem();
	dp[2][1][1] = a[1][1];
	for (int i = 2; i <= m + n; i++){
		for (int i1 = 1; i1 <= n; i1++){
			for (int i2 = 1; i2 <= n; i2++){
				if (dp[i][i1][i2] == -1) continue;
				int j1 = i - i1, j2 = i - i2;
				for (pair<int, int> d1 : d){
					for (pair<int, int> d2 : d){
						int nx1 = i1 + d1.fi, ny1 = j1 + d1.se, nx2 = i2 + d2.fi, ny2 = j2 + d2.se;
						if ((1 <= nx1 && nx1 <= n) && (1 <= ny1 && ny1 <= m) && (1 <= nx2 && nx2 <= n) && (1 <= ny2 && ny2 <= m)){
							dp[i + 1][nx1][nx2] = max(dp[i + 1][nx1][nx2], dp[i][i1][i2] + a[nx1][ny1] + a[nx2][ny2] - ((nx1 == nx2) && (ny1 == ny2)) * a[nx1][ny1]);
						}
					}
				}
			}
		}
	}

	cout << dp[n + m][n][n];
}

signed main(){
	if (fopen(task ".inp", "r"))
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
