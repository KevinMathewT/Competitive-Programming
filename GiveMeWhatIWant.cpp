#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (ll) 1e9 + 10

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, q;
vector<pair<ll, ll> > adj[(ll)1e5+10];
ll lca[(ll)1e5+10][18];
ll minw[(ll)1e5+10][18];
ll vis[(ll)1e5+10];
ll depth[(ll)1e5+10];

void dfs(ll x, ll d){
	vis[x] = 1;
	depth[x] = d;

	for(ll i=0;i<adj[x].size();i++){
		if(vis[adj[x][i].first] != 1){
			lca[adj[x][i].first][0] = x;
			minw[adj[x][i].first][0] = adj[x][i].second;
		}
	}

	for(ll i=0;i<adj[x].size();i++)
		if(vis[adj[x][i].first] != 1)
			dfs(adj[x][i].first, d+1);
}

void query(ll u, ll v, ll w){
	ll ans = LLONG_MAX;
	if(depth[u] > depth[v]){
		ll t = u;
		u = v;
		v = t;
	}

	ll diff = depth[v] - depth[u];

	for(ll i=0;i<18;i++) 
        if((diff >> i) & 1){ 
        	ans = min(ans, minw[v][i]);
            v = lca[v][i];
        }

    if (u == v){
        cout << min(ans, w) << "\n";
        return;
    }

    for (ll i=17; i>=0; i--){ 
    	// cout << lca[u][i] << " " << lca[v][i] << "\n";
        if (lca[u][i] != lca[v][i]) 
        {
        	ans = min(ans, min(minw[u][i], minw[v][i]));
            u = lca[u][i]; 
            v = lca[v][i]; 
        }
    }

    // cout << minw[u][0] << " " << minw[v][0] << "\n";

	ans = min((ll) ans, (ll) min(minw[u][0], minw[v][0]));

    cout << min(w, ans) << "\n";
}

void te(){
	cin >> n >> q;

	for(ll i=0;i<(ll)1e5+10;i++)
		vis[i] = 0;

	for(ll i=0;i<(ll)1e5+10;i++){
		adj[i].clear();
		for(ll j=0;j<18;j++)
			lca[i][j] = -1;
	}

	for(ll i=0;i<(ll)1e5+10;i++)
		for(ll j=0;j<18;j++)
			minw[i][j] = (ll) 1e9 + 10;

	for(ll i=0;i<(ll)1e5+10;i++)
		depth[i] = 0;

	for(ll i=1;i<n;i++){
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}

	for(ll i=1;i<=n;i++)
		if(vis[i] != 1)
			dfs(i, 0);

	for(ll j=1;j<18;j++)
		for(ll i=1;i<=n;i++)
			if(lca[i][j] == -1){
				lca[i][j] = lca[lca[i][j-1]][j-1];
				minw[i][j] = min(minw[i][j-1], minw[lca[i][j-1]][j-1]);
			}

	while(q--){
		ll u, v, w;
		cin >> u >> v >> w;
		query(u, v, w);
	}
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
		te();

	return 0;
}