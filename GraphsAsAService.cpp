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

struct edges{
	int u, v, w;
};

ll INF = 1e12;
ll n, m, dist[110][110], temp[110][110], vis[110][110];
edges z[1010];

void solve(ll T){
	cin >> n >> m;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++){
			vis[i][j] = 0;
			if(i == j)
				temp[i][j] = dist[i][j] = 0;
			else
				temp[i][j] = dist[i][j] = INF;
		}

	for(ll i=0;i<m;i++){
		ll a, b, c;
		cin >> a >> b >> c;

		z[i].u = a - 1;
		z[i].v = b - 1;
		z[i].w = c;
	}

	for(ll i=0;i<m;i++){
		// cout << z[i].u << " " << z[i].v << " " << z[i].w << "\n";
		dist[z[i].u][z[i].v] = z[i].w;
		temp[z[i].u][z[i].v] = z[i].w;
		vis[z[i].u][z[i].v] = 1;

		dist[z[i].v][z[i].u] = z[i].w;
		temp[z[i].v][z[i].u] = z[i].w;
		vis[z[i].v][z[i].u] = 1;
	}

	for(ll k=0;k<n;k++)
		for(ll i=0;i<n;i++)
			for(ll j=0;j<n;j++)
            	if (dist[i][k] < INF && dist[k][j] < INF)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++){
			if(vis[i][j] == 1 && temp[i][j] != dist[i][j] && i != j){
				cout << "Case #" << T << ": Impossible\n";
				return;
			}
		}

	// cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";

	// for(ll i=0;i<n;i++){
	// 	for(ll j=0;j<n;j++){
	// 		cout << dist[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	// cout << "...............\n";

	// for(ll i=0;i<n;i++){
	// 	for(ll j=0;j<n;j++){
	// 		cout << temp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	// cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";

	ll out = 0;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			if(i < j && dist[i][j] < INF)
				out++;

	cout << "Case #" << T << ": " << out << "\n";

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			if(i < j && dist[i][j] < INF)
				cout << i + 1 << " " << j + 1 << " " << dist[i][j] << "\n";
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
	for(ll i=1;i<=T;i++)
		solve(i);

	return 0;
}