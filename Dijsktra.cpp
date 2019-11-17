#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, start, dist[100010], vis[100010];
vector<pair<ll, ll> > graph[100010];

void solve(){
	cin >> n >> m;
	for(ll i=0;i<m;i++){
		ll u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(w, v));
		graph[v].push_back(make_pair(w, u));
	}

	for(ll i=1;i<=n;i++){
		dist[i] = 1e9;
		vis[i] = 0;
	}

	priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;

	pq.push(make_pair(0, 1));
	// dist[1]=0;
	while(!pq.empty()){
		pair<ll, ll> a = pq.top();
		pq.pop();
		ll u = a.second;
		vis[u] = 1;
		for(ll i=0;i<graph[u].size();i++){
			ll v = graph[u][i].second;
			ll w = graph[u][i].first;
			ll distance = a.first + w;
			if(distance < dist[v])
				{dist[v]=distance;
			pq.push(make_pair(distance, v));
		}
		}
	}

	for(ll i=1;i<=n;i++)
		cout << dist[i] << " ";
	cout << "\n";
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