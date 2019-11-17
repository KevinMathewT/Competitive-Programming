#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

struct Node{
	ll sum_even, sum_odd;
	ll present;
};

ll m, queries[100010][2], n, tme, order[400010], vis[100010], depth[400010], pos, in[400010], out[400010];
vector<ll> tree[100010];
Node stree[400010];

void dfs_order(ll u, ll dth){
	order[pos] = u;
	in[u] = pos;
	depth[pos++] = dth & 1;
	vis[u] = 1;

	for(ll v : tree[u]){
		if(vis[v] != 1)
			dfs_order(v, dth + 1);
	}

	order[pos] = u;
	out[u] = pos;
	depth[pos++] = dth & 1;
}

void update(ll i, ll l, ll r, ll p){
	if(l == r){
		stree[i].present = 1;
		return;
	}

	ll mid = (l + r) / 2;

	if(p <= mid)
		update(2*i, l, mid, p);
	if(p > mid)
		update(2*i + 1, mid + 1, r, p);

	stree[i].sum_even = stree[2*i].present * stree[2*i].sum_even + stree[2*i].present * stree[2*i + 1].sum_even;
	stree[i].sum_odd = stree[2*i].present * stree[2*i].sum_odd + stree[2*i].present * stree[2*i + 1].sum_odd;
	stree[i].present = 1;
}

pair<ll, ll> query(ll i, ll l, ll r, ll a, ll b){
	pair<ll, ll> ret0 = {0, 0};

	if(b < l || a > r)
		return ret0;
	if(a >= l && b <= r)
		return {stree[i].present * stree[i].sum_even, stree[i].present * stree[i].sum_odd};

	ll mid = (l + r) / 2;
	pair<ll, ll> x = query(2 * i, l, mid, a, b);
	pair<ll, ll> y = query(2 * i + 1, mid + 1, r, a, b);

	pair<ll, ll> ret = {x.first + y.first, x.second + y.second};
}

void build(ll i, ll l, ll r){
	if(l == r){
		if(depth[order[l]] == 1){
			stree[i].sum_even = 1;
			stree[i].sum_odd = 0;
			stree[i].present = 0;
		}
		else{
			stree[i].sum_even = 0;
			stree[i].sum_odd = 1;
			stree[i].present = 0;
		}
		return;
	}

	ll mid = (l + r) / 2;

	build(2*i, l, mid);
	build(2*i + 1, mid + 1, r);

	stree[i].sum_even = stree[2*i].present * stree[2*i].sum_even + stree[2*i].present * stree[2*i + 1].sum_even;
	stree[i].sum_odd = stree[2*i].present * stree[2*i].sum_odd + stree[2*i].present * stree[2*i + 1].sum_odd;
	stree[i].present = 1;
}

void solve(){
	fill(vis, vis + 100010, 0);
	pos = 0;
	n = 0;
	cin >> m;
	for(ll i=0;i<m;i++){
		ll t, v;
		cin >> t >> v;

		if(t == 0){
			tree[v].push_back(n++);
		}

		queries[i][0] = t;
		queries[i][1] = m;
	}

	build(0, 0, pos - 1);

	for(ll i=0;i<m;i++){
		if(queries[i][0] == 0)
			update(0, 0, pos - 1, queries[i][1]);
		if(queries[i][1] == 1){
			pair<ll, ll> x = query(0, 0, pos - 1, in[queries[i][1]], out[queries[i][1]]);
			cout << (((x.first / 2) * ((x.first / 2) - 1)) / 2 + ((x.second / 2) * ((x.second / 2) - 1)) / 2) << "\n";
		}
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