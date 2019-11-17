#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, r, m, vis[1000100];
vector<ll> graph[1000100];

void init(){
	for(ll i=0;i<1000100;i++)
		vis[i] = 0;
}

void te(){
	cin >> n >> r >> m;
	for(ll i=0;i<n;i++)
		graph[i].clear();
	for(ll i=0;i<r;i++){
		ll u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	init();

	queue<pair<pair<ll, ll>, ll> > q;
	for(ll i=0;i<m;i++){
		ll k, s;
		cin >> k >> s;
		q.push(make_pair(make_pair(k, s), i + 1));
		vis[k] = i + 1;
	}

	while(!q.empty()){
		pair<pair<ll, ll>, ll> a = q.front();
		q.pop();
		
		// cout << a.first.first << " " << a.first.second << " " << a.second << "\n";

		if(vis[a.first.first] != 0 && vis[a.first.first] != a.second){
			cout << "No\n";
			return;
		}

		vis[a.first.first] = a.second;
		if(a.first.second == 0)
			continue;

		for(ll v : graph[a.first.first]){
			// cout << v << " " << vis[v] << "--\n";
			if(vis[v] != a.second)
				q.push(make_pair(make_pair(v, a.first.second - 1), a.second));
		}
	}

	for(ll i=1;i<=n;i++)
		if(vis[i] == 0){
			cout << "No\n";
			return;
		}

	cout << "Yes\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}