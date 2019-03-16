#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SIZE (ll) 1e3+10

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m;
vector<pair<ll, ll> > adj[SIZE];
ll vis[SIZE], dist[SIZE];

void te(){
	cin >> n >> m;
	for(ll i=0;i<m;i++){
		ll u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back(make_pair(d, v));
		adj[v].push_back(make_pair(d, u));
	}

	for(ll i=0;i<SIZE;i++){
		vis[i] = 0;
		dist[i] = 0;
	}

	priority_queue<pair<ll, ll> > pq;

	pq.push(make_pair(0, 1));

	while(!pq.empty()){
		pair<ll, ll> curr = pq.top();
		pq.pop();
		ll u = curr.second;
		ll w = curr.first;
		vis[u] = 1;
		dist[u] = w;

		for(ll i=0;i<adj[u].size();i++)
			if(vis[adj[u][i].second] != 1)
				pq.push(make_pair(w+adj[u][i].first, adj[u][i].second));
	}

	ll k;
	cin >> k;
	ll ans = LLONG_MIN;
	ll prev_time = 0, curr_time = 0, prev_loc = 1;

	while(k--){
		ll s, u, t;
		cin >> s >> u >> t;

		prev_time = curr_time + dist[prev_loc];

		curr_time = max(s, max(t, prev_time)) + dist[u];

		cout << prev_time << " " << curr_time << " " << s << "\n";
		prev_loc = u;

		ans = max(ans, curr_time - s);
	}

	cout << ans << "\n";
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