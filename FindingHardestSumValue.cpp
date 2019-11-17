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

ll n, m, a[1010][1010], dp[1010][1010][4]; 

void solve(){
	cin >> n >> m;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			cin >> a[i][j];

	for(ll i=0;i<n;i++){
		dp[i][0][0] = a[i][0];
		for(ll j=1;j<m;j++)
			dp[i][j][0] = dp[i][j-1][0] + a[i][j];
	}

	for(ll i=0;i<m;i++){
		dp[0][i][1] = a[0][i];
		for(ll j=1;j<n;j++)
			dp[j][i][1] = dp[j-1][i][1] + a[j][i];
	}

	for(ll i=0;i<n;i++){
		dp[i][0][2] = dp[i][0][0];
		for(ll j=1;j<m;j++)
			dp[i][j][2] = max(dp[i][j-1][2], dp[i][j][0]);
	}


	for(ll i=0;i<n;i++){
		dp[i][m-1][3] = dp[i][m-1][0];
		for(ll j=m-2;j>=0;j--)
			dp[i][j][3] = min(dp[i][j+1][3], dp[i][j][0]);
	}

	for(ll i=0;i<m;i++){
		dp[0][i][4] = dp[0][i][1];
		for(ll j=1;j<n;j++)
			dp[j][i][4] = max(dp[j-1][i][4], dp[j][i][1]);
	}

	for(ll i=0;i<m;i++){
		dp[n-1][i][5] = dp[n-1][i][1];
		for(ll j=n-2;j>=0;j--)
			dp[j][i][5] = min(dp[j+1][i][5], dp[j][i][1]);
	}

	ll ans = LLONG_MAX;

	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			cout << dp[i][j][2] - dp[i][j][3] + dp[i][j][4] - dp[i][j][5] << " ";
			ans = min(ans, dp[i][j][2] - dp[i][j][3] + dp[i][j][4] - dp[i][j][5]);
		}

		cout << "\n";
	}

	cout << ans << "\n";
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
		solve();

	return 0;
}