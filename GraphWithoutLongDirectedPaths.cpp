#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, disc[200010], vis[200010], flag;
vector<ll> graph[200010], even, odd;
vector<pair<ll, ll> > edges;
unordered_map<ll, ll> um; 

void dfs(ll x, ll time){
	// if(disc[x] != -1)
	// cout << x << " " << time << "\n";
	disc[x] = time;

	for(ll v : graph[x]){
		if(disc[v] != -1 && (time + 1 - disc[v]) % 2 != 0)
			flag = 1;
		if(disc[v] == -1)
			dfs(v, time + 1);
	}
}

void te(){
	flag = 0;
	cin >> n >> m;
	for(ll i=1;i<=n;i++)
		disc[i] = -1;
	for(ll i=0;i<m;i++){
		ll u, v;
		cin >> u >> v;
		edges.push_back(make_pair(u, v));
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1, 0);

	if(flag){
		cout << "NO\n";
		return;
	}
	else{
		cout << "YES\n";
		for(ll i=0;i<m;i++){
			// cout << disc[edges[i].first] << " " << 
			if(disc[edges[i].first] % 2 == 0 && disc[edges[i].second] % 2 == 1)
				cout << 1;
			else
				cout << 0;
		}
	}
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