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

ll n, a[1000010], dp[1000010];

void solve(){
	fill(dp, dp + 10010, 0);
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	// sort(a, a + n);

	for(ll i=0;i<n;i++){
		for(ll j=1;j<=10000;j++)
			dp[__gcd(a[i], j)] += dp[j];
		// if(a[i] != 1)
			dp[a[i]]++;
	}

	ll c = 0;
	for(ll i=0;i<n;i++)
		if(a[i] == 1)
			c++;

	cout << (dp[1] - c) << "\n";
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