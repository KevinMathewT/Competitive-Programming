#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, costs[(ll) 1e5+10], m;
vector<ll> v[(ll) 1e5+10];
vector<ll> scc[(ll) 1e5+10];
stack<ll> s;
ll dfs_num[(ll) 1e5+10], dfs_low[(ll) 1e5+10], vis[(ll) 1e5+10];
ll z, counter;

void dfs(ll vert){
	dfs_num[vert] = counter;
	dfs_low[vert] = counter++;
	s.push(vert);
	vis[vert] = 1;

	for(ll i=0;i<v[vert].size();i++){
		if(dfs_num[v[vert][i]] == -1){
			dfs(v[vert][i]);
		}
		if(vis[v[vert][i]] == 1)
			dfs_low[vert] = min(dfs_low[vert], dfs_low[v[vert][i]]);
	}

	if(dfs_num[vert] == dfs_low[vert]){
		while(true){
			ll u = s.top();
			s.pop();
			vis[u] = 0;

			scc[vert].push_back(u);

			if(u == vert)
				break;
		}
	}
}

void memset(ll *a, int b, ll size){
	for(ll i=0;i<size;i++)
		a[i] = b;
}

void te(){
	z = counter = 0;
	cin >> n;

	memset(costs, -1, n+10);
	memset(dfs_num, -1, n+10);
	memset(dfs_low, -1, n+10);
	memset(vis, 0, n+10);

	for(ll i=1;i<=n;i++)
		cin >> costs[i];

	cin >> m;

	for(ll i=0;i<m;i++){
		ll a, b;
		cin >> a >> b;

		v[a].push_back(b);
	}

	for(ll i=1;i<=n;i++){
		if(dfs_num[i] == -1){
			dfs(i);	
		}
	}

	ll tot = 0;
	vector<ll> mul;
	ll z = 0;

	ll c = 0;

	for(ll i=0;i<=n;i++){
		if(scc[i].size() == 0)
			continue;

		ll minimum = LLONG_MAX;
		mul.push_back(0);

		for(ll j=0;j<scc[i].size();j++){
			minimum = min(minimum, costs[scc[i][j]]);
		}

		tot = tot + minimum;

		for(ll j=0;j<scc[i].size();j++){
			if(minimum == costs[scc[i][j]])
				mul[z] = (mul[z] + 1) % ((ll) (1e9 + 7));
		}

		z++;
	}

	ll final = 1;
	for(ll i=0;i<mul.size();i++)
		final = (final * mul[i]) % ((ll) (1e9 + 7));

	cout << tot << " " << final << "\n";
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