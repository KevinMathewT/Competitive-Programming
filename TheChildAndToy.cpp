#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew

void te(){
	ll n, m; cin >> n >> m;
	ll a[n+1];
	
	for(ll i=1;i<=n;i++) cin >> a[i];

	vector<ll> v[n+1];
	for(ll i=0;i<m;i++){
		ll p, q; cin >> p >> q;
		v[p].push_back(q);
		v[q].push_back(p);
	}

	ll cost[n+1];
	for(ll i=1;i<=n;i++) cost[i] = 0;
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<v[i].size();j++){
			cost[i] += a[v[i][j]];
		}
		// cout << cost[i] << " ";
	}

	// cout << "\n";

	ll tot = 0;
	for(ll i=0;i<n-1;i++){
		// for(ll j=1;j<=n;j++) cout << a[j] << " ";
		// cout << "\n";
		ll min_val = LLONG_MIN, pos = -1;
		for(ll j=1;j<=n;j++){
			if(min_val < a[j]){
				pos = j;
				min_val = a[j];
			}
		}
		// cout << min_val << " -- \n";
		tot += cost[pos];
		for(ll j=0;j<v[pos].size();j++)
			cost[v[pos][j]] -= a[pos];

		a[pos] = LLONG_MIN;

		// for(ll j=1;j<=n;j++) cout << a[j] << " ";
		// cout << "\n";
	}

	cout << tot << "\n";
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