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

ll n, r, q, vis[100010], dp[100010][6];
vector<ll> tree[100010];

void dfs(ll u){
	vis[u] = 1;
	dp[u][0] = -1;

	for(ll v : tree[u]){
		if(vis[v] == 0){
			dfs(v);
			dp[u][0] = max(dp[u][0], dp[v][0]);
		}
	}

	dp[u][0] += 1;
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
		dp[u][1] = max(dp[u][1], vec[vec.size() - 1] + vec[vec.size() - 2] + 2);
}

void dfs2(ll u){
	vis[u] = 1;
	ll mx1 = 0, mx2 = 0, mx3 = -1, mx4 = -1;

	for(ll v : tree[u]){
		if(vis[v] == 0){
			if(dp[v][1] > mx1) mx2 = mx1, mx1 = dp[v][1];
			else if(dp[v][1] > mx2) mx2 = dp[v][1];
		}
	}

	for(ll v : tree[u]){
		if(vis[v] == 0){
			if(dp[v][0] > mx3) mx4 = mx3, mx3 = dp[v][0];
			else if(dp[v][0] > mx4) mx4 = dp[v][0];
		}
	}

	for(ll v : tree[u]){
		if(vis[v] == 0){
			if(dp[v][0] == mx3) dp[v][3] = 1 + max(dp[u][3], mx4);
			else dp[v][3] = 1 + max(dp[u][3], mx3);
		}
	}

	for(ll v : tree[u]){
		if(vis[v] == 0){
			if(dp[v][0] == mx3) dp[v][5] = 2 + dp[u][3] + mx4;
			else dp[v][5] = 2 + dp[u][3] + mx3;
		}
	}


	for(ll v : tree[u]){
		if(vis[v] == 0){
			if(dp[v][1] == mx1) dp[v][2] = mx2;
			else dp[v][2] = mx1;
			dp[v][4] = dp[v][1] * max(dp[v][2], max(dp[v][3], dp[v][5]));
			dfs2(v);
		}
	}
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

	fill(vis, vis + 100010, 0);
	dfs(0);

	fill(vis, vis + 100010, 0);
	dfs1(0);

	fill(vis, vis + 100010, 0);
	dp[0][3] = -1;
	dfs2(0);

	for(ll i=0;i<n;i++)
		cout << dp[i][0] << " ";
	cout << "\n";
	for(ll i=0;i<n;i++)
		cout << dp[i][1] << " ";
	cout << "\n";
	for(ll i=0;i<n;i++)
		cout << dp[i][2] << " ";
	cout << "\n";
	for(ll i=0;i<n;i++)
		cout << dp[i][3] << " ";
	cout << "\n";
	for(ll i=0;i<n;i++)
		cout << dp[i][4] << " ";
	cout << "\n";
	for(ll i=0;i<n;i++)
		cout << dp[i][5] << " ";
	cout << "\n";
	cout << "\n";

	ll mx = 0;
	for(ll i=0;i<n;i++)
		mx = max(mx, dp[i][4]);
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