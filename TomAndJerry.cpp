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

ll n, q, x[1000010], t[1000010], vis[1000010];
vector<ll> tree[1000010];

ll dfs(ll u, ll xr){
	xr = xr ^ t[u];
	x[u] = xr;
	vis[u] = 1;

	for(ll v : tree[u]){
		if(vis[v] != 1)
			dfs(v, xr);
	}
}

void solve(){
	cin >> n;
	fill(x, x + 1000010, 0);
	fill(vis, vis + 1000010, 0);
	for(ll i=0;i<n-1;i++){
		ll u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	for(ll i=1;i<=n;i++)
		cin >> t[i];

	dfs(1, 0);

	cin >> q;
	while(q--){
		ll u, v;
		cin >> u >> v;
		// cout << x[u] << " " << x[v] << "\n";
		cout << (x[u] ^ x[v]) << "\n";
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