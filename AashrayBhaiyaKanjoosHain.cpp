#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, q, max_depth, depth[100010], hash[100010], revHash[100010], parent[18][100010], vis[100010];
char c[100010];
vector<ll> tree[100010];
const ll p = 31, m = 1e9 + 9;

void findParents(ll x, ll d, ll h, ll revH, ll p_pow){
	max_depth = max(max_depth, d);
	hash[x] = (h + (((c[x] - 'a' + 1) * p_pow) % m)) % m;
	revHash[x] = (((revH * p) % m) + (c[x] - 'a' + 1)) % m;
	depth[x] = d;
	vis[x] = 1;
	for(ll i=0;i<tree[x].size();i++)
		if(vis[tree[x][i]] != 1){
			parent[0][tree[x][i]] = x;
			findParents(tree[x][i], d + 1, hash[x], revHash[x], (p_pow * p) % m);
		}
}

void findGrandParents(){
	for(ll i=1;i<=17;i++)
		for(ll j=1;j<=n;j++)
			if(parent[i-1][j] != -1)
				parent[i][j] = parent[i-1][parent[i-1][j]];
}

ll power(ll x, ll y){
	if(y == 1) return x % m;
	if(y == 0) return 1;

	if(y % 2 == 0)
		return modExpo((x * x) % m, y / 2);
	else
		return (x * modExpo((x * x) % m, y / 2)) % m;
}

ll LCA(ll u, ll v){
	if(u == v) return u;

	ll diff = depth[u] - depth[v];
	if(diff < 0){
		swap(u, v);
		diff = -diff;
	}

	for(ll i=0;i<17;i++)
		if((1<<i) & diff)
			u = parent[i][u];

	if(u == v)
		return u;

	for(ll i=17;i>=0;i--)
		if(parent[i][u] != parent[i][v]){
			u = parent[i][u];
			v = parent[i][v];
		}

	return parent[0][u];
}

ll raise(ll v, ll h){
	for(ll i=0;i<18;i++)
		if((1<<i) & h)
			v = parent[i][v];

	return v;
}

ll query(ll u, ll v){
	ll lca = LCA(u, v);
	ll path = (depth[u] - depth[lca]) + (depth[v] - depth[lca]) + 1;
	ll left = (depth[u] - depth[lca]);
	ll right = (depth[v] - depth[lca]);

	ll l = 0, r = path / 2, mid;

	while(l < r){
		mid = (l + r) / 2;
		ll h1 = 0, h2 = 0;
		ll f = u, s = v;

		if(mid <= left){
			f = raise(f, mid);
			h1 = (((hash[u] - hash[f] + m) % m) * (power(power(p, depth[f]-1)), m-2)) % m;
		}

		if(mid == left+1){
			if(lca == 1)
				h1 = hash[u];
			else
				h1 = (((hash[u] - hash[parent[0][lca]] + m) % m) * (power(power(p, depth[parent[0][lca]]-2)), m-2)) % m;
		}

		if(mid > left+1){
			if(lca == 1)
				h1 = hash[u];
			else
				h1 = (((hash[u] - hash[parent[0][lca]] + m) % m) * (power(power(p, depth[parent[0][lca]]-2)), m-2)) % m;
			ll temp = mid;
			temp -= left;


		}
	}
}

void te(){
	max_depth = 0;
	cin >> n;
	for(ll i=0;i<n-1;i++){
		ll u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	for(ll i=0;i<100010;i++)
		for(ll j=0;j<18;i++)
			parent[j][i] = -1;

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