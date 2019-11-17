#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, c[100010], vis[100010];
vector<ll> graph[100010];
vector<ll> curr;
ll ans;

ll dfs(ll x){
	vis[x] = 1;

	ll mn = c[x];
	for(ll i=0;i<graph[x].size();i++)
		if(vis[graph[x][i]] == 0)
			mn = min(mn, dfs(graph[x][i]));

	return mn;
}

void te(){
	ans = 0;
	cin >> n >> m;
	for(ll i=0;i<n;i++){
		vis[i] = 0;
		cin >> c[i];
	}

	for(ll i=0;i<m;i++){
		ll u, v;
		cin >> u >> v;
		u--; v--;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(ll i=0;i<n;i++)
		if(vis[i] == 0)
			cost += dfs(i);

	cout << cost << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}