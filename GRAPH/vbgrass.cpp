#include <bits/stdc++.h>
#define int long long
#define task "task"
#define fi first
#define se second
using namespace std;

const int ma = 104;
int r, c, res = 0;
bool vis[ma][ma];
char a[ma][ma];

int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

void Read() {
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) cin >> a[i][j];
	}
}

void bfs(int u, int v) {
	vis[u][v] = true;
	queue<pair<int, int>> q;
	q.push({u, v});
	while(!q.empty()) {
		int i = q.front().fi, j = q.front().se;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = i + x[k], ny = j + y[k];
			if ((1 <= nx && nx <= r) && (1 <= ny && ny <= c) && !vis[nx][ny] && a[nx][ny] == '#') {
				vis[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
}

void solve() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (a[i][j] == '#' && vis[i][j] == false) {
				res++;
				bfs(i, j);
			}
		}
	}

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

