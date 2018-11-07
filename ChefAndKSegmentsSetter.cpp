#include <bits/stdc++.h>
 
using namespace std;
 
const int MaxN = (int)2e5 + 10;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;  

int n, k;
int l[MaxN], r[MaxN];
int ord[MaxN];

bool cmp(int x, int y) {
	return l[x] < l[y] || l[x] == l[y] && r[x] < r[y];
}

int rnd(int l, int r) {
	return (1LL * RAND_MAX * rand() + rand()) % (r - l + 1) + l;
}

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &l[i], &r[i]);
		ord[i] = i;
	}
	sort(ord + 1, ord + n + 1, cmp);
	multiset <int> rr;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		rr.insert(r[ord[i]]);
		if ((int)rr.size() > k) {
			rr.erase(rr.begin());
		}
		if (i >= k) {
			ans = max(ans, *rr.begin() - l[ord[i]]);
		}
	}
	cout << ans << "\n";
}


int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	srand(time(NULL));
	int t = 1e4;
	scanf("%d", &t);
	while (t --> 0) {
		solve();
	}
	return 0;
}