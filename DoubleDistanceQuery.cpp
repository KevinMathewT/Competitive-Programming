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

ll n, q, vis[100010];
vector<ll> tree[100010];

void dfs(ll u, ll d, vector<ll> &a){
	vis[u] = 1;
	if(d == 0){
		a.push_back(u);
		return;
	}

	for(ll v : tree[u])
		if(vis[v] == 0)
			dfs(v, d - 1, a);
}

void solve(){
	cin >> n >> q;
	for(ll i=0;i<100010;i++)
		tree[i].clear();
	for(ll i=0;i<n-1;i++){
		ll u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	while(q--){
		ll a, da, b, db;
		cin >> a >> da >> b >> db;

		vector<ll> c(0, 0), d(0, 0);
		fill(vis, vis + n + 10, 0);
		dfs(a, da, c);
		fill(vis, vis + n + 10, 0);
		dfs(b, db, d);		

		ll flag1 = 0, flag2 = 0;
		for(ll i=0;i<c.size();i++){
			if(flag2 == 1)
				break;
			for(ll j=0;j<d.size();j++)
				if(c[i] == d[j]){
					cout << c[i] << "\n";
					flag2 = 1;
					break;
				}
		}

		if(flag2 != 1)
			cout << -1 << "\n";
	}
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
		solve();

	return 0;
}