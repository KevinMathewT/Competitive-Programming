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

ll n, val[100010], vis[100010], h;
vector<ll> graph[100010], pre[100010], suff[100010];
unordered_map<ll, vector<ll> > m;
unordered_map<ll, ll> g;

dfs(ll x, ll d){
	h = max(h, d);
	vis[x] = 1;
	m[d].push_back(x);

	for(ll v : graph[x]){
		if(vis[v] != 1)
			dfs(v, d + 1);
	}
}

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++){
		cin >> val[i];
		vis[i] = 0;
	}

	for(ll i=0;i<n-1;i++){
		ll u, v;
		cin >> u >> v;
		u--; v--;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	h = 0;
	dfs(0, 0);
	h++;

	for(ll i=0;i<h;i++){
		ll x = val[m[i][0]];
		for(ll j=1;j<m[i].size();j++)
			x = __gcd(x, val[m[i][j]]);

		g[i] = x;
	}

	// for(ll i=0;i<h;i++)
	// 	cout << g[i] << " ";

	for(ll i=0;i<h;i++){
		vector<ll> v(m[i].size());
		pre[i] = v;
		pre[i][0] = val[m[i][0]];
		for(ll j=1;j<m[i].size();j++){
			pre[i][j] = __gcd(pre[i][j-1], (ll)val[m[i][j]]);
		}
	}

	for(ll i=0;i<h;i++){
		vector<ll> v(m[i].size());
		suff[i] = v;
		suff[i][m[i].size()-1] = val[m[i][m[i].size()-1]];
		for(ll j=max((ll)0, (ll)m[i].size()-2);j>=0;j--){
			suff[i][j] = __gcd(suff[i][j+1], (ll)val[m[i][j]]);
		}
	}

	ll tot = 0;

	for(ll i=0;i<h;i++)
		tot += g[i];

	ll mx = tot;

	for(ll i=0;i<h;i++){
		if(m[i].size() == 1){
			mx = max(mx, 1000000 + tot - g[i]);
		}

		for(ll j=0;j<m[i].size();j++){
			if(j == 0)
				mx = max(mx, __gcd(suff[i][1], tot - g[i]));
			else if(j == (m[i].size() - 1))
				mx = max(mx, __gcd(pre[i][m[i].size()-2], tot - g[i]));
			else
				mx = max(mx, __gcd(pre[i][j-1], __gcd(suff[i][j+1], tot - g[i])));
		}
	}

	cout << mx << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}