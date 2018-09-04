#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew

ll max_height = 0, h = 0;
ll vis[3000];
vector<ll> v[3000];

ll dfs(ll n, ll h){
	h++;
	max_height = max(max_height, h);
	vis[n] = 1;
	for(ll i=0;i<v[n].size();i++)
		if(vis[v[n][i]] == 0)
			dfs(v[n][i], h);
}

void te(){
	ll n; cin >> n;
	for(ll i=1;i<=n;i++) vis[i] = 0;
	ll val[n+1];
	for(ll i=1;i<=n;i++){
		ll a; cin >> a;
		val[i] = a;
		if(a == -1) continue;
		v[i].push_back(a);
		v[a].push_back(i);
	}

	// for(ll i=1;i<=n;i++){
	// 	for(ll j=0;j<v[i].size();j++)
	// 		cout << v[i][j] << " ";
	// 	cout << "\n";
	// }
	for(ll i=1;i<=n;i++)
		if(vis[i] == 0 && val[i] == -1){
			dfs(i, 0);
		}

	cout << max_height << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	// ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}