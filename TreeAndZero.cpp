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

ll n, val[100010], ans[100010], M = (ll)(1e9 + 7), vis[100010];
vector<ll> tree[100010];

ll binExp(ll x, ll a){
	if(a == 0)
		return 1;
	if(a == 1)
		return x;
	if(a % 2 == 0)
		return binExp((x * x) % M, a / 2);
	return (x * binExp((x * x) % M, a / 2)) % M;
}

ll getNum(ll x){
	ll z = 1;
	ll pos = 0;
	while(z <= x){
		if((z & x) == 0)
			pos++;
		z = z * 2;
	}

	cout << x << " " << binExp(2, pos) << "\n";

	return binExp(2, pos);
}

void dfs(ll x, ll curr){
	vis[x] = 1;
	ans[x] = (getNum(val[x-1]) * curr) % M;

	for(ll v : tree[x]){
		if(vis[v] != 1)
			dfs(v, ans[x]);
	}
}

void solve(){
	fill(vis, vis + 100010, 0);
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> val[i];
	for(ll i=2;i<=n;i++){
		ll v;
		cin >> v;
		tree[i].push_back(v);
		tree[v].push_back(i);
	}

	dfs(1, 1);

	for(ll i=1;i<=n;i++)
		cout << ans[i] << " ";
	cout << "\n";
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