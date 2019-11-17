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

ll n, m, a[300010], dp[300010];

void solve(){
	cin >> n >> m;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll mx = 0;
	fill(dp, dp + 300010, 0);
	for(ll i=m;i<n;i++){
		dp[i] = dp[i-m] + a[i];
		mx = max(mx, dp[i]);
	}

	cout << mx << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}