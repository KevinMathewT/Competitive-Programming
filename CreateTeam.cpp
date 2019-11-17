#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, w[1010], p[1010];

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> p[i];
	for(ll i=0;i<n;i++)
		cin >> w[i];
	cin >> m;

	ll dp[n+10][m+10];
	for(ll i=0;i<n+10;i++)
		for(ll j=0;j<m+10;j++)
			dp[i][j] = 0;
	for(ll i=0;i<n;i++)
		dp[i][0] = 0;
	for(ll i=0;i<=m;i++)
		if(i < w[0])
			dp[0][i] = 0;
		else
			dp[0][i] = p[0];

	for(ll i=1;i<n;i++)
		for(ll j=1;j<=m;j++)
			if(j < w[i])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j], p[i] + dp[i-1][j-w[i]]);

	cout << dp[n-1][m] << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}