#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, k, co[100010], dp[100010], vis[100010];
vector<ll> tree[100010];
unordered_map<ll, ll> um;

ll dfs(ll x){
	vis[x] = 1;
	ll sum = 0;
	for(ll v : tree[x]){
		if(vis[v] == 0)
			sum += dfs(v);
	}

	dp[x] = sum;
	return 1 + dp[x];
}

void te(){
	cin >> n >> k;
	um.clear();
	for(ll i=0;i<=n;i++){
		tree[i].clear();
		dp[i] = 0;
		vis[i] = 0;
		co[i] = 0;
	}
	for(ll i=0;i<n-1;i++){
		ll u, v;
		cin >> u >> v;
		co[v] = 1;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	for(ll i=1;i<=n;i++)
		if(co[i] == 0){
			dfs(i);
			break;
		}

	ll strength = 0;
	for(ll i=1;i<=n;i++)
		strength += dp[i];

	sort(dp + 1, dp+n+1);
	ll weak = 0;
	for(ll i=1;i<=n;i++)
		weak += ((dp + n + 1) - lower_bound(dp+1, dp+n+1, dp[i]+k));

	cout << strength << " " << weak << "\n";
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
		te();

	return 0;
}