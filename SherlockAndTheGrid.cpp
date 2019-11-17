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

ll n, dp[1010][1010];
char a[1010][1010];

void solve(){
	for(ll i=0;i<1010;i++)
		fill(dp[i], dp[i] + 1010, 0);
	cin >> n;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			cin >> a[i][j];
	for(ll i=0;i<n;i++)
		for(ll j=n-1;j>=0;j--)
			if(a[i][j] == '#')
				break;
			else
				dp[i][j] = 1;

	// for(ll i=0;i<n;i++){
	// 	for(ll j=0;j<n;j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << "\n";
	// }

	ll c = 0;
	for(ll i=0;i<n;i++)
		for(ll j=n-1;j>=0;j--){
			if(a[j][i] == '#')
				break;
			if(dp[j][i] == 1)
				c++;
		}

	cout << c << "\n";
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
	while(T--)
		solve();

	return 0;
}