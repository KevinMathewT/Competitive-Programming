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

ll n, x, a[30][30], fact[30], dp[21][21][100010];

void solve(){
	cin >> n >> x;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++){
			cin >> a[i][j];
			for(ll k=0;k<=x;k++)
				dp[i][j][k] = 0;
		}

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++){
			if(i == 0 || j == 0){
				if(a[i][j] <= x && i == 0 && j == 0)
					dp[i][j][a[i][j]]++;


				if(i == 0 && j == 0)
					continue;

				if(i == 0){
					for(ll k=0;k<=x;k++){
						if(k + a[i][j] <= x)
							dp[i][j][k + a[i][j]] += dp[i][j-1][k];
					}
				}

				if(j == 0){
					for(ll k=0;k<=x;k++){
						if(k + a[i][j] <= x)
							dp[i][j][k + a[i][j]] += dp[i-1][j][k];
					}
				}
				continue;
			}

			for(ll k=0;k<=x;k++){
				if(k + a[i][j] <= x)
					dp[i][j][k + a[i][j]] += dp[i][j-1][k];
			}
		
			for(ll k=0;k<=x;k++){
				if(k + a[i][j] <= x)
					dp[i][j][k + a[i][j]] += dp[i-1][j][k];
			}
		}

	// for(ll i=0;i<=x;i++)
	// 	cout << dp[n-1][n-1][i] << ' ';
	// cout << "\n";

	cout << accumulate(dp[n-1][n-1], dp[n-1][n-1] + x + 1, (ll) 0) << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	fact[0] = 1;
	for(ll i=1;i<=20;i++)
		fact[i] = i * fact[i-1];

	// cout << LLONG_MAX << "\n";

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}