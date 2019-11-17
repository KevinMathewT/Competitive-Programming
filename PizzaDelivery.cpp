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

ll n, a[1010], b[1010], dp[1010];

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];
	for(ll i=0;i<n;i++)
		cin >> b[i];
	for(ll i=0;i<1010;i++)
		dp[i] = INT_MAX;
	for(ll i=0;i<n;i++)
		dp[b[i]] = 1;
	for(ll i=2;i<=1010;i++)
		for(ll j=1;j<i;j++)
			dp[i] = min(dp[j] + dp[i - j], dp[i]);
	ll tot = 0;
	for(ll i=0;i<n;i++)
		tot += dp[2 * a[i]];
	cout << tot << "\n";
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