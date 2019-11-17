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

ll n, p, vis[100010];
vector<ll> graph[100010];
unordered_map<string, ll> um;

ll dfs(ll u, ll x){
	vis[u] = 1;
	ll ret = 0;
	for(ll v : graph[u]){
		if(v == x)
			return 1;
		if(vis[v] == 0)
			ret |= dfs(v, x);
	}

	return ret;
}

void solve(){
	for(ll i=0;i<100010;i++)
		graph[i].clear();
	um.clear();
	p = 0;
	for(ll i=0;i<n;i++){
		string s, t;
		cin >> s >> t;
		if(um.find(s) == um.end()) um[s] = p++;
		if(um.find(t) == um.end()) um[t] = p++;
		fill(vis, vis + 100010, 0);
		if(dfs(um[t], um[s])){
			cout << s << " " << t << "\n";
			for(ll j=i+1;j<n;j++)
				cin >> s >> t;
				// cout << s << " " << t << "\n";
			return;
		}

		graph[um[s]].push_back(um[t]);
	}

	cout << 0 << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	while(cin >> n)
		solve();

	return 0;
}