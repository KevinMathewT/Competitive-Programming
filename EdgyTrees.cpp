#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, k, vis[100010];
vector<ll> graph[100010];
vector<ll> components;

ll mod_pow(ll a, ll x){
	if(x == 0)
		return 1;
	if(x == 1)
		return a % 1000000007;

	if(x % 2 == 0)
		return mod_pow((a * a) % 1000000007, x / 2);
	else
		return (mod_pow((a * a) % 1000000007, x / 2) * a) % 1000000007;
}

ll dfs(ll x){
	vis[x] = 1;
	ll ret = 1;

	for(ll v : graph[x])
		if(vis[v] == 0)
			ret += dfs(v);

	return ret;
}

void te(){
	cin >> n >> k;
	components.clear();
	for(ll i=0;i<=n;i++)
		vis[i] = 0;
	for(ll i=0;i<n-1;i++){
		ll u, v, x;
		cin >> u >> v >> x;
		if(x == 1)
			continue;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(ll i=1;i<=n;i++)
		if(vis[i] == 0)
			components.push_back(dfs(i));

	ll tot = mod_pow(n, k);
	for(ll i=0;i<components.size();i++)
		tot = (tot - mod_pow(components[i], k) + 1000000007) % 1000000007;

	cout << tot << "\n";
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