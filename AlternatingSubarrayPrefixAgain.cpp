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

ll n, a[100010], dp[100010];

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];
	dp[n-1] = 1;

	for(ll i=n-2;i>=0;i--)
		if((a[i] * a[i+1]) < 0)
			dp[i] = dp[i+1] + 1;
		else
			dp[i] = 1;

	for(ll i=0;i<n;i++)
		cout << dp[i] << ' ';
	cout << "\n";
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