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

ll n, r, q, vis[100010], dp[100010][2];
vector<ll> tree[100010];

void dfs(ll u){
	vis[u] = 1;
	dp[u][0] = 0;
	// cout << u << ' ' << dp[u][0] << "\n";

	for(ll v : tree[u]){
		if(vis[v] == 0){
			dfs(v);
			dp[u][0] = max(dp[u][0], dp[v][0]);
		}
	}

	dp[u][0] += 1;
	// cout << u << ' ' << dp[u][0] << "\n";
}

void dfs1(ll u){
	vis[u] = 1;
	dp[u][1] = dp[u][0];

	vector<ll> vec(0);

	for(ll v : tree[u]){
		if(vis[v] == 0){
			dfs1(v);
			vec.push_back(dp[v][0]);
			dp[u][1] = max(dp[u][1], dp[v][1]);
		}
	}

	sort(vec.begin(), vec.end());

	if(vec.size() >= 2)
		dp[u][1] = max(dp[u][1], vec[vec.size() - 1] + vec[vec.size() - 2] + 1);
}

void solve(){
	cin >> n;
	for(ll i=0;i<n-1;i++){
		ll u, v;
		cin >> u >> v;
		u--; v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	cin >> r;
	r--;

	fill(vis, vis + 100010, 0);
	dfs(r);
	
	// for(ll i=0;i<n;i++)
	// 	cout << dp[i][0] << " ";
	// cout << "\n";
	// for(ll i=0;i<n;i++)
	// 	cout << dp[i][1] << " ";
	// cout << "\n";

	fill(vis, vis + 100010, 0);
	dfs1(r);

	// for(ll i=0;i<n;i++)
	// 	cout << dp[i][0] << " ";
	// cout << "\n";
	// for(ll i=0;i<n;i++)
	// 	cout << dp[i][1] << " ";
	// cout << "\n";
	
	cin >> q;
	while(q--){
		ll query;
		cin >> query;
		cout << dp[query - 1][1] - 1 << "\n";
	}
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