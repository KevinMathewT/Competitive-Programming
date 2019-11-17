#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define L 25

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, q, parent[1000010][L], d[1000010];
vector<ll> tree[1000010];

void dfs(ll u, ll p, ll di){
	parent[u][0] = p;
	d[u] = di;
	for(ll v : tree[u])
		if(v != p)
			dfs(v, u, di + 1);
}

ll raise(ll x, ll v){
	for(ll i=0;i<L && x != -1;i++)
		if(v & (1 << L))
			x = parent[x][L];

	return x;
}

ll LCA(ll u, ll v){
	if(u == v) return u;
	if(d[u] != d[v])
		if(d[u] > d[v])
			u = raise(u, d[u] - d[v]);
		else
			v = raise(v, d[v] - d[u]);

	if(u == v)
		return u;

	while(u != v)
		for(ll i=L-1;i>=0;i--)
			if(parent[u][i] != parent[v][i]){
				u = parent[u][i];
				v = parent[v][i];
				break;
			}

	u = parent[u][0];

	return u;
}

void solve(){
	cin >> n >> q;
	for(ll i=0;i<n-1;i++){
		ll u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	for(ll i=1;i<=n;i++)
		for(ll j=0;j<L;j++)
			parent[i][j] = 0;

	dfs(1, 0, 0);

	for(ll i=1;i<L;i++)
		for(ll j=1;j<=n;j++)
			parent[j][i] = parent[parent[j][i-1]][i-1];

	while(q--){
		ll a, da, b, db;

		cin >> a >> da >> b >> db;
		ll lca = LCA(a, b);

		if((da + db) != (d[a] + d[b] - (2 * d[lca]))){
			cout << "-1\n";
			continue;
		}

		if(da <= (d[lca] - d[a]))
			cout << raise
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
		solve();

	return 0;
}