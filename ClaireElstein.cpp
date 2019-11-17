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

ll n, m, in[100010], out[100010], vis[100010], dp[100010], tot, M = 1000000007;
vector<ll> graph[100010];

ll dfs(ll u, ll time){
	if(dp[u] != -1)
		return dp[u];

	vis[u] = 1;

	if(graph[u].size() == 0){
		vis[u] = 0;
		return (time % M);
	}

	ll ret = 0;

	for(int v : graph[u]){
		if(vis[v] == 0)
			ret = (ret + dfs(v, time + 1)) % M;
	}

	vis[u] = 0;
	return dp[u] = ret;
}

void solve(){
	fill(graph, graph + 100010, vector<ll>(0));
	fill(in, in + 100010, 0);
	fill(out, out + 100010, 0);
	fill(vis, vis + 100010, 0);
	fill(dp, dp + 100010, -1);

	tot = 0;

	cin >> n >> m;

	for(ll i=0;i<m;i++){
		ll u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		out[u]++;
		in[v]++;
	}

	for(ll i=1;i<=n;i++)
		if(in[i] == 0)
			tot = (tot + dfs(i, 0)) % M;

	cout << tot << "\n";
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