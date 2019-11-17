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

ll n, dp[100010][2], vis[100010];
vector<ll> tree[100010];

void dfs(ll u){
	vis[u] = 1;

	for(ll v : tree[u])
		if(vis[v] == 0)
			dfs(v);

	if(tree[u].size() == 0){
		dp[u][0] = 0;
		dp[u][1] = 1;
		return;
	}

	ll sum1 = 0, sum2 = 0;

	for(ll v : tree[u]){
		sum1 += dp[v][0];
		sum2 += dp[v][1];
	}	

	dp[u][0] = sum2;
	dp[u][1] = 1;

	for(ll v : tree[u])
		dp[u][1] += min(dp[v][0], dp[v][1]);
}

void solve(){
	fill(dp[0], dp[0] + 100010, 0);
	fill(dp[1], dp[1] + 100010, 0);
	fill(vis, vis + 100010, 0);
	cin >> n;
	for(ll i=0;i<n-1;i++){
		ll u, v;
		cin >> u >> v;
		u--; v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(0);

	cout << min(dp[0][0], dp[0][1]);
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