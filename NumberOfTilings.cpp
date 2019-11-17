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

ll n, dp[1000010][3], M;

void solve(){
	M = 10000;
	cin >> n;
	for(ll i=0;i<=n;i++)
		for(ll j=0;j<3;j++)
			dp[i][j] = 0;

	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[1][2] = 0;
	dp[2][0] = 1;
	dp[2][1] = 2;
	dp[2][2] = 1;

	for(ll i=3;i<=n;i++){
		dp[i][0] = (dp[i-2][1] + dp[i-1][2]) % M;
		dp[i][1] = (dp[i-2][1] + dp[i-1][1] + dp[i-1][0] + dp[i-1][2]) % M;
		dp[i][2] = (dp[i-2][1] + dp[i-1][0]) % M;
}

	cout << dp[n][1] << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}