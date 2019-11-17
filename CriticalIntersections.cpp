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

ll n, m, disc[500], low[500], vis[500], cutp[500], tot;
vector<ll> graph[500], res;

ll dfs(ll u, ll t, ll p = -1){
	vis[u] = 1;
	disc[u] = t;

	ll child = 0;
	low[u] = disc[u];

	for(ll v : graph[u]){
		if(v == p) continue;
		if(vis[v] == 1) low[u] = min(low[u], disc[v]);
		if(vis[v] != 1){
			dfs(v, t + 1, u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= disc[u] && p != -1){
				// cout << u << ' ' << v << "\n";
				cutp[u] = 1;
			}
			child++;
		}
	}

	if(p == -1 && child > 1)
		cutp[u] = 1;
}

void solve(){
	tot = 0;
	cin >> n >> m;
	for(ll i=0;i<m;i++){
		ll u, v;
		cin >> u >> v; u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	fill(cutp, cutp + n, 0);
	dfs(0, 0);
	for(ll i=0;i<n;i++)
		if(cutp[i] == 1)
			tot++, res.push_back(i + 1);

	cout << tot << "\n";
	for(ll i=0;i<tot;i++)
		cout << res[i] << "\n";
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