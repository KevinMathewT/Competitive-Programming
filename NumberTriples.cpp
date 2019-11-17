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

ll m, a, b, dist[4000010], num;
vector<pair<ll, ll> > graph[4000010];
unordered_map<ll, ll> um;

void solve(){
	num = 0;
	fill(dist, dist + 4000010, LLONG_MAX);
	cin >> m >> a >> b;
	a--;
	b--;

	if(um.find(a) == um.end())
		um[a] = num++;
	if(um.find(b) == um.end())
		um[b] = num++;

	for(ll i=0;i<m;i++){
		ll u, w, v;
		cin >> u >> w >> v;
		u--;
		v--;
		if(um.find(u) == um.end())
			um[u] = num++;
		if(um.find(v) == um.end())
			um[v] = num++;

		u = um[u];
		v = um[v];

		graph[u].push_back(make_pair(w, v));
		graph[v].push_back(make_pair(w, u));
	}

	// for(ll i=0;i<=5;i++){
	// 	cout << i << "-> ";
	// 	for(auto v : graph[i])
	// 		cout << v.S << " ";
	// 	cout << "\n";
	// }

	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll> > > pq;
	pq.push(make_pair((ll)0, um[a]));
	dist[um[a]] = 0;

	while(!pq.empty()){
		pair<ll, ll> p = pq.top(); pq.pop();
		// cout << p.F << " " << p.S << "\n";

		for(ll i=0;i<graph[p.S].size();i++){
			pair<ll, ll> pll = graph[p.S][i];
			if((pll.F + dist[p.S]) < dist[pll.S]){
				dist[pll.S] = (pll.F + dist[p.S]);
				// cout << (pll.F + p.F) << ' ' << pll.S << " ";
				pq.push(make_pair((pll.F + p.F), pll.S));
			}
		}

		// cout << "\n";
	}

	if(dist[um[b]] == LLONG_MAX)
		cout << "NO\n";
	else
		cout << "YES\n" << dist[um[b]] << "\n";
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