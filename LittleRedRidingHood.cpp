#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, m, a[510][510], b[10010][3], safe[510][510], vis[510][510];
pair<ll, ll> dp[510][510];

void MakeSafe(ll x, ll y, ll limit, ll n) {
    for (ll l = 1; l <= limit; l++)
        for (ll i = max(x - l, (ll)1); i <= min(x + l, n); i++)
            for (ll j = max(y - (l - abs(x - i)), (ll)1); j <= min(y + (l - abs(x - i)), n); j++)
                safe[i-1][j-1] = 1;
}

pair<ll, ll> dfs(ll x, ll y){
	if(safe[x][y] == 0 || x >= n || y >= n || x < 0 || y < 0)
		return {0, 0};
	if(x == n-1 && y == n-1)
		return dp[x][y] = {1, a[x][y]};
	if(dp[x][y].F != -1)
		return dp[x][y] = dp[x][y];
	ll p1 = 0, p2 = 0;

	pair<ll, ll> pll1 = dfs(x + 1, y);
	pair<ll, ll> pll2 = dfs(x, y + 1);

	p1 |= pll1.F;
	p1 |= pll2.F;

	if(p1 == 0)
		return dp[x][y] = {0, 0};
	if(pll1.F == 0)
		return dp[x][y] = {1, pll2.S + a[x][y]};
	if(pll2.F == 0)
		return dp[x][y] = {1, pll1.S + a[x][y]};

	return dp[x][y] = {1, max(pll2.S + a[x][y], pll1.S + a[x][y])};
}

void solve(){
	cin >> n >> m;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++){
			vis[i][j] = safe[i][j] = 0;
			dp[i][j] = {-1, -1};
			cin >> a[i][j];
		}

	for(ll i=0;i<m;i++)
		for(ll j=0;j<3;j++)
			cin >> b[i][j];

	queue<pair<ll, pair<ll, ll> > > q;
	for(ll i=0;i<m;i++)
		MakeSafe(b[i][0], b[i][1], b[i][2], n);

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			vis[i][j] = 0;

	pair<ll, ll> pll = dfs(0, 0);

	if(pll.F == 0)
		cout << "NO\n";
	else{
		cout << "YES\n";
		cout << pll.S << "\n";
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}