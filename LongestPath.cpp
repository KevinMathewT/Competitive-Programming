#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m;
vector<ll> G[100010];
vector<ll> revG[100010];
vector<ll> roots;
ll vis[100010];
unordered_map<ll, ll> um;
ll dp[100010];

ll dfs(ll x){
	if(dp[x] != -1)
		return dp[x];

	ll ans = 0;

	for(ll i=0;i<G[x].size();i++){
		// cout << x << " " << G[x][i] << "-\n";
		ans = max(ans, dfs(G[x][i]));
	}

	dp[x] = ans + 1;

	// cout << x << " " << dp[x] << "\n";
	return dp[x];
}

void te(){
	cin >> n >> m;
	for(ll i=0;i<n;i++){
		vis[i+1] = 0;
		dp[i+1] = -1;
	}
	
	for(ll i=0;i<m;i++){
		ll u, v;
		cin >> u >> v;

		G[u].push_back(v);
		revG[v].push_back(u);
	}

	for(ll i=1;i<=n;i++){
		if(revG[i].size() == 0)
			roots.push_back(i);
	}

	ll ans = 0;
	for(ll i=0;i<roots.size();i++){
		// cout << roots[i] << "\n";
		ans = max(ans, dfs(roots[i]));
	}

	cout << ans - 1 << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}