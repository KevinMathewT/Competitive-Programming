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

ll n, m, vis[5010], k, color[5010];
vector<pair<ll, ll> > graph[5010];

void dfs(ll u){
	vis[u] = 2;
	for(pair<ll, ll> p : graph[u]){
		if(vis[p.F] == 2){
			k = 2;
			color[p.S] = 2;
		}
		else if(vis[p.F] == 0)
			dfs(p.F);
	}
	vis[u] = 1;
}

void solve(){
	cin >> n >> m;
	for(ll i=0;i<m;i++){
		ll u, v;
		cin >> u >> v;
		graph[u - 1].push_back({v - 1, i});
	}

	fill(vis, vis + n, 0);
	fill(color, color + m, 1);

	k = 1;

	for(ll i=0;i<n;i++)
		if(vis[i] == 0)
			dfs(i);

	cout << k << "\n";
	for(ll i=0;i<m;i++)
		cout << color[i] << " ";
	cout << "\n";
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