#include <bits/stdc++.h>
#define int long long
#define task "task"
#define fi first
#define se second
using namespace std;

const int ma = 20, inf = 1e18;
int n, c[ma][ma], dp[1 << ma][ma];

void Read() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> c[i][j];
	}
}

void mem() {
	for (int i = 0; i < n; i++) {
		for (int mask = 0; mask < (1 << n); mask++) dp[mask][i] = inf;
	}

	for (int i = 0; i < n; i++) {
		dp[(1 << i)][i] = 0;
	}
}

void solve() {
	mem();
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int j = 0; j < n; j++) {
			if (dp[mask][j] == inf) continue;
			for (int i = 0; i < n; i++) {

				if ((mask >> i) & 1) continue;
				int nmask = mask | (1 << i);
				dp[nmask][i] = min(dp[nmask][i], dp[mask][j] + c[j][i]);
			}
		}
	}

	int res = inf;
	for (int i = 0; i < n; i++) res = min(res, dp[(1 << n) - 1][i]);
	cout << res;
}

signed main() {
	if(fopen(task ".inp", "r")) {
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

