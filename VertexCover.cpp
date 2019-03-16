#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SIZE (ll)1e5+10

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n;
vector<ll> tree[SIZE];
ll dp[SIZE][2];

ll dfs(ll x, ll state, ll p){
	// cout << x << " " << state << " " << p << "\n";

	if(dp[x][state] != -1)
		return dp[x][state];

	ll sum = 0;

	// if(tree[x].size() == 1)
	// 	return 1;

	if(state == 0){
		for(ll i=0;i<tree[x].size();i++){
			if(tree[x][i] == p) continue;
			sum += min(dfs(tree[x][i], 0, x), dfs(tree[x][i], 1, x));
		}

		return dp[x][state] = 1 + sum;
	}
	else{
		for(ll i=0;i<tree[x].size();i++){
			if(tree[x][i] == p) continue;
			sum += dfs(tree[x][i], 0, x);
		}

		return dp[x][state] = sum;	
	}
}

void te(){
	cin >> n;
	for(ll i=1;i<n;i++){
		ll u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	for(ll i=0;i<SIZE;i++)
		dp[i][0] = dp[i][1] = -1; 

	cout << min(dfs(1, 0, -1), dfs(1, 1, -1)) << "\n";
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