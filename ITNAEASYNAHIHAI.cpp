#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, dist[710][710], col[710][710], row[710][710], vis[710][710];

void te(){
	cin >> n >> m;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++){
			cin >> dist[i][j];
			vis[710][710] = 0;
		}

	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			cin >> row[i][j];

	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			cin >> col[i][j];

	priority_queue<pair<ll, pair<ll, ll>>> pq;
	pq.push(make_pair(0, make_pair(0, 0)));

	while(!pq.empty()){
		pair<ll, pair<ll, ll>> pp = pq.top();
		pq.pop();

		ll x = pp.S.F;
		ll y = pp.S.S;
		ll cost = pp.F;

		cout << x << " " << y << " " << cost << "\n";

		if(x == n-1 && y == m-1){
			cout << -cost << "\n";
			return;
		}

		if(vis[pp.S.F][pp.S.S] == 1)
			continue;

		vis[pp.S.F][pp.S.S] = 1;

		// if((x + dist[x][y]) < n){
			pair<ll, pair<ll, ll>> a;
			a.F = (cost - col[x][y]);
			a.S.F = (x + dist[x][y]) % n;
			a.S.S = y;
			pq.push(a);
		// }

		// if((y + dist[x][y]) < m){
			// pair<ll, pair<ll, ll>> a;
			a.F = (cost - row[x][y]);
			a.S.F = x;
			a.S.S = (y + dist[x][y]) % m;
			pq.push(a);
		// }

		// if((x - dist[x][y]) >= 0){
			// pair<ll, pair<ll, ll>> a;
			a.F = (cost - col[x][y]);
			a.S.F = (((x - dist[x][y]) % n) + n) % n;
			a.S.S = y;
			pq.push(a);
		// }

		// if((y - dist[x][y]) >= 0){
			// pair<ll, pair<ll, ll>> a;
			a.F = (cost - row[x][y]);
			a.S.F = x;
			a.S.S = (((y - dist[x][y]) % m) + m) % m;
			pq.push(a);
		// }
	}

	cout << -1 << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// cout << -6 % 5 << "\n";
	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}