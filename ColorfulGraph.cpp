#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, colors[100010];
vector<ll> adjList[100010];
map<ll, ll> diversity[100010];
map<ll, ll> divCount;

void te(){
	cin >> n >> m;
	for(ll i=1;i<=n;i++)
		cin >> colors[i];

	for(ll i=0;i<m;i++){
		ll u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	ll ans = 1, maximum = LLONG_MIN;

	for(ll i=1;i<=n;i++){
		for(ll j=0;j<adjList[i].size();j++)
			if(diversity[colors[i]][colors[adjList[i][j]]] != 1 && colors[adjList[i][j]] != colors[i]){
				divCount[colors[i]]++;
				diversity[colors[i]][colors[adjList[i][j]]] = 1;
			}

		if(divCount[colors[i]] > maximum ||( divCount[colors[i]] == maximum && colors[i] < ans)){
			ans = colors[i];
			maximum = divCount[colors[i]];
		}
	}

	cout << ans << "\n";
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