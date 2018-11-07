#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, vis[(ll) 1e5 + 100];
vector<ll> vec[(ll) 1e5 + 100];

void dfs(ll node){
	if(vis[node] == 1)
		return;
	vis[node] = 1;
	for(ll i=0;i<vec[node].size();i++)
		dfs(vec[node][i]);
}

void te(){
	cin >> n;
	for(ll i=0;i<(ll) 1e5 + 100;i++)
		vis[i] = 0;
	for(ll i=1;i<=n;i++){
		ll a;
		cin >> a;
		vec[i].push_back(a);
		vec[a].push_back(i);
	}

	ll c = 0;
	for(ll i=1;i<=n;i++){
		if(vis[i] == 0){
			c++;
			dfs(i);
		}
	}

	cout << c << "\n";
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