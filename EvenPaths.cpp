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

ll n, m, x, dp[100010][2], vis[100010];
vector<ll> tree[100010];

void dfs(ll u, ll d){
	vis[u] = 1;

	for(ll v : tree[u]){
		if(vis[v] != 1)
			dfs(v);
		if(d % 2 == 1)
			dp[v][0]++;
	}

	vis[u] = 0;
}

void solve(){
	fill(vis, vis + 100010, 0);
	cin >> n >> m >> x;
	for(ll i=0;i<m;i++){
		ll u, v;
		cin >> u >> v;
		tree[u].push_back(v);
	}

	for(ll i=1;i<=n;i++)
		cout << dp[i][0] << " ";
	cout << "\n";
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