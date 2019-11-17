#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, vis[10010];
vector<ll> graph[10010];

void te(){
	cin >> n >> m;
	for(ll i=1;i<=n;i++){
		graph[i].clear();
		vis[i] = 0;
	}
	for(ll i=0;i<m;i++){
		ll u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	queue<pair<ll, ll>> q;
	q.push(make_pair(1, 0));

	while(!q.empty()){
		pair<ll, ll> p = q.front();;
		q.pop();
		vis[p.first] = 1;

		if(p.first == n){
			cout << p.second << "\n";
			return;
		}

		for(ll v : graph[p.first]){
			if(vis[v] == 0)
				q.push(make_pair(v, p.second + 1));
		}
	}

	cout << "Impossible\n";
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