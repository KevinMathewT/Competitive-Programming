#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, adj[510][510], x[510], floyd[510][510], vis[510], output[510];

void te(){
	cin >> n;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			cin >> adj[i][j];

	for(ll i=n;i>=1;i--)
		cin >> x[i];

	for(ll i=0;i<=n;i++){
		vis[i] = 0;
		for(ll j=0;j<=n;j++)
			floyd[i][j] = LLONG_MAX/2;
	}

	for(ll i=1;i<=n;i++){
		vis[x[i]] = 1;
		// cout << x[i] << "--\n";
		ll ans = 0;
		
		// for(ll j=1;j<=n;j++){
		// 	for(ll k=1;k<=n;k++){
		// 		if(vis[j] == 1 && vis[k] == 1){
		// 			floyd[j][k] = min(floyd[j][k], adj[j][k]);
		// 		}
		// 	}
		// }

		for(ll j=1;j<=n;j++){
			for(ll k=1;k<=n;k++){
				if(vis[j] == 1 && vis[k] == 1){
					adj[x[i]][k] = min(adj[x[i]][j] + adj[j][k], adj[x[i]][k]);
					adj[k][x[i]] = min(adj[k][j] + adj[j][x[i]], adj[k][x[i]]);
				}
			}
		}
		
		for(ll j=1;j<=n;j++){
			for(ll k=1;k<=n;k++){
				if(vis[j] == 1 && vis[k] == 1){
					adj[k][j] = min(adj[k][x[i]] + adj[x[i]][j], adj[k][j]);
					adj[j][k] = min(adj[j][x[i]] + adj[x[i]][k], adj[j][k]);
				}
			}
		}

		for(ll j=1;j<=n;j++){
			for(ll k=1;k<=n;k++){
				if(vis[j] == 1 && vis[k] == 1){
					ans += adj[j][k];
				}
			}
		}
		// for(ll j=1;j<=n;j++){
		// 	for(ll k=1;k<=n;k++){
		// 		cout << adj[j][k] << "\t\t";
		// 	}
		// 	cout << "\n";
		// }

		output[n-i+1] = ans;
		// cout << "\n\n";
	}

	for(ll i=1;i<=n;i++)
		cout << output[i] << " ";
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