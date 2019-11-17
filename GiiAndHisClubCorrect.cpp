#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, k, a[20][20], tot;
vector<ll> sums[20];

void dfs(ll x, ll y, ll sum){
	if(a[x][y] > k)
		return;
	if(x + y == n - 1){
		sums[x].push_back(sum + a[x][y]);
		return;
	}

	dfs(x + 1, y, sum + a[x][y]);
	dfs(x, y + 1, sum + a[x][y]);
}

void dfs2(ll x, ll y, ll sum){
	if(a[x][y] > k)
		return;
	if(x + y == n - 1){
		tot += sums[x].size() - (sums[x].end() - upper_bound(sums[x].begin(), sums[x].end(), (k - sum)));
		return;
	}

	dfs2(x - 1, y, sum + a[x][y]);
	dfs2(x, y - 1, sum + a[x][y]);
}

void solve(){
	cin >> n >> k;
	tot = 0;
	for(ll i=0;i<n;i++){
		sums[i].clear();
		for(ll j=0;j<n;j++)
			cin >> a[i][j];
	}

	if(n == 1){
		if(a[0][0] <= k)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
		return;
	}

	dfs(0, 0, 0);

	for(ll i=0;i<n;i++)
		sort(sums[i].begin(), sums[i].end());

	dfs2(n-1, n-1, 0);

	cout << tot << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}