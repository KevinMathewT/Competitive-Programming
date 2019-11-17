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

ll n, m, vis[100010];
vector<ll> graph[100010];

ll dfs(ll u){
	vis[u] = 1;
	ll ret = 1;
	for(ll v : graph[u])
		if(vis[v] != 1)
			ret += dfs(v);
	return ret;
}

void solve(){
	cin >> n >> m;
	for(ll i=0;i<m;i++){
		ll u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	fill(vis, vis + n + 10, 0);
	ll tot = 0;
	for(ll i=1;i<=n;i++)
		if(vis[i] != 1)
			tot += (dfs(i)) / 2;

	cout << tot << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}