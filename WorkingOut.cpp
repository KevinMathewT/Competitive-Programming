#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, a[1010][1010], dp1[1010][1010], dp2[1010][1010], dp3[1010][1010], dp4[1010][1010];

void te(){
	cin >> n >> m;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
			cin >> a[i][j];

	for(ll i=0;i<=n+1;i++)
		for(ll j=0;j<=m+1;j++){
			dp1[i][j] = 0;
			dp2[i][j] = 0;
			dp3[i][j] = 0;
			dp4[i][j] = 0;
		}

	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
			dp1[i][j] = a[i][j] + max(dp1[i-1][j], dp1[i][j-1]);

	for(ll i=n;i>=1;i--)
		for(ll j=m;j>=1;j--)
			dp2[i][j] = a[i][j] + max(dp2[i+1][j], dp2[i][j+1]);

	for(ll i=n;i>=1;i--)
		for(ll j=1;j<=m;j++)
			dp3[i][j] = a[i][j] + max(dp3[i+1][j], dp3[i][j-1]);

	for(ll i=1;i<=n;i++)
		for(ll j=m;j>=1;j--)
			dp4[i][j] = a[i][j] + max(dp4[i-1][j], dp4[i][j+1]);

	ll mx = LLONG_MIN;
	ll ans = 0;

	for(ll i=2;i<n;i++){
		for(ll j=2;j<m;j++){
			ans = max(dp1[i-1][j] + dp2[i+1][j] + dp3[i][j-1] + dp4[i][j+1], dp1[i][j-1] + dp2[i][j+1] + dp3[i+1][j] + dp4[i-1][j]);
			mx = max(mx, ans);
		}
		// cout << "\n";
	}

	cout << mx << "\n";
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