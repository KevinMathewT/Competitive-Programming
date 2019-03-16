#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, a[50];

void te(){
	cin >> n >> m;
	for(ll i=0;i<n;i++){
		ll k;
		cin >> k;
		for(ll i=0;i<k;i++){
			ll u;
			cin >> u;
			a[u]++;
		}
	}

	ll ans = 0;
	for(ll i=1;i<=m;i++)
		if(a[i] == n)
			ans++;

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