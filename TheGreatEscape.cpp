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

ll n, m, s, t, vis[3510];
vector<ll> graph[3510];

void solve(){
	cin >> n >> m;
	for(ll i=0;i<m;i++){
		ll u, v;
		cin >> u >> v;
		u--;
		v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	fill(vis, vis + 3510, 0);

	cin >> s >> t; s--; t--;

	queue<pair<ll, ll> > q;
	q.push({s, 0});

	while(!q.empty()){
		pair<ll, ll> p = q.front();
		q.pop();
		if(p.F == t){
			cout << p.S << "\n";
			return;
		}

		for(ll v : graph[p.F])
			if(vis[v] != 1)
				vis[v] = 1, q.push({v, p.S + 1});
	}

	cout << "0\n";
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