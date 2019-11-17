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

ll n, k, s[400], vis[400];
vector<ll> id[400], graph[400];

ll dfs(ll u, ll p){
	vis[u] = 1;
	ll ret = 1;
	for(ll v : graph[u])
		if(vis[v] != 1)
			ret += dfs(v, u);

	return ret;
}

ll similar(vector<ll> &a, vector<ll> &b){
	unordered_map<ll, ll> m2;
	for(ll i=0;i<b.size();i++)
		m2[b[i]] = 1;
	ll sim = 0;
	for(ll i=0;i<a.size();i++)
		if(m2[a[i]] == 1)
			sim++;

	return sim;
}

void solve(){
	fill(vis, vis + 400, 0);
	
	cin >> n >> k;
	for(ll i=0;i<n;i++){
		cin >> s[i];
		for(ll j=0;j<s[i];j++){
			ll x; cin >> x;
			id[i].push_back(x);
		}
	}

	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			if(similar(id[i], id[j]) >= k){
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	cout << dfs(0, -1) << "\n";
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