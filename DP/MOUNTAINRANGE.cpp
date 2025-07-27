#include <bits/stdc++.h>
#define int long long
#define task "task"
#define fi first
#define se second
using namespace std;
 
const int ma = 2e5 + 4;
int n, dp[ma], L[ma], R[ma], st[ma * 4];
pair<int, int> h[ma];
stack<int> s;
 
void update(int id, int tl, int tr, int pos, int val) {
	if (tl == tr) {
		st[id] = val;
		return;
	}
 
	int mid = (tl + tr) >> 1;
	if (pos <= mid) update(id * 2, tl, mid, pos, val);
	else update(id * 2 + 1, mid + 1, tr, pos, val);
	st[id] = max(st[id * 2], st[id * 2 + 1]);
}
 
int get(int id, int tl, int tr, int l, int r) {
	if (l > tr ||  r < tl) return LLONG_MIN;
	if (l <= tl && tr <= r) return st[id];
	int mid = (tl + tr) >> 1;
	return max(get(id * 2, tl, mid, l, r), get(id * 2 + 1, mid + 1, tr, l, r));
}

void Read() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i].fi;
		h[i].se = i;
	}
 
	for (int i = 1; i <= n; i++) {
		while (!s.empty() && h[s.top()].fi < h[i].fi) s.pop();
		if (s.empty()) L[i] = 1;
		else L[i] = s.top() + 1;
		s.push(i);
	}
 
	while (!s.empty()) s.pop();
	for (int i = n; i >= 1; i--) {
		while (!s.empty() && h[s.top()].fi < h[i].fi) s.pop();
		if (s.empty()) R[i] = n;
		else R[i] = s.top() - 1;
		s.push(i);
	}
 
	sort(h + 1, h + 1 + n);
}
 
void solve() {
	for (int i = 1; i <= n; i++) {
		dp[h[i].se] = get(1, 1, n, L[h[i].se], R[h[i].se]) + 1;
		update(1, 1, n, h[i].se, dp[h[i].se]);
	}
 
	cout << *max_element(dp + 1, dp + 1 + n);
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
