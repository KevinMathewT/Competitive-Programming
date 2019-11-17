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

ll n, a[100010], f[100010], dp[100010];

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];
	for(ll i=0;i<100010;i++)
		f[i] = 0;
	for(ll i=0;i<n;i++)
		f[a[i]] = 1;

	dp[0] = 0;
	dp[1] = f[1];

	for(ll i=2;i<=*max_element(a, a + n);i++)
		dp[i] = max(i * f[i] + dp[i-2], dp[i-1]);

	cout << dp[*max_element(a, a + n)] << "\n";
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