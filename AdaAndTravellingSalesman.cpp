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

ll n, q, a[100010], dp[100010][2];
vector<ll> tree[100010];

void dfs(ll u, ll p){
	dp[u][0] = 0;
	for(ll v : tree[u]){
		if(v == p) continue;
		dfs(v, u);
		dp[u][0] = max(dp[u][0], max(0LL, a[v] - a[u]) + dp[v][0]);
	}
}

void dfs1(ll u, ll p){
	ll max1 = 0, max2 = 0;
	for(ll v : tree[u]){
		if(v == p) continue;
		if((max(0LL, a[v] - a[u]) + dp[v][0]) > max1) max2 = max1, max1 = (max(0LL, a[v] - a[u]) + dp[v][0]);
		else if((max(0LL, a[v] - a[u]) + dp[v][0]) > max2) max2 = (max(0LL, a[v] - a[u]) + dp[v][0]);
		dp[v][1] = max(0LL, (max(0LL, a[u] - a[v]) + dp[u][1]));
	}

	for(ll v : tree[u]){
		if(v == p) continue;

		if((max(0LL, a[v] - a[u]) + dp[v][0]) == max1)
			dp[v][1] = max(dp[v][1], max(0LL, (max(0LL, a[u] - a[v]) + max2)));
		else dp[v][1] = max(dp[v][1], max(0LL, (max(0LL, a[u] - a[v]) + max1)));

		dfs1(v, u);
	}
}

void solve(){
	cin >> n >> q;
	for(ll i=0;i<n;i++)
		cin >> a[i];
	for(ll i=0;i<n-1;i++){
		ll u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(0, -1);
	dfs1(0, -1);

	while(q--){
		ll query;
		cin >> query;
		cout << max(dp[query][0], dp[query][1]) << "\n";
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