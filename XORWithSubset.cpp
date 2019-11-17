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

ll n, k, a[1010], dp[2010];

void solve(){
	fill(dp, dp + 2010, 0);
	cin >> n >> k;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	dp[0] = 1;
	for(ll i=0;i<n;i++){
		for(ll j=1;j<=1024;j++)
			dp[a[i] ^ j] = dp[a[i] ^ j] | dp[j];
		dp[a[i]] = 1;
	}

	ll mx = k;

	for(ll i=1;i<=1024;i++)
		if(dp[i])
			mx = max(mx, k ^ i);

	cout << mx << "\n";
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