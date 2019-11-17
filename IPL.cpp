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

ll n, a[200010], dp[200010];

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	if(n <= 3){
		cout << *min_element(a, a + n) << "\n";
		return;
	}

	for(ll i=0;i<3;i++)
		dp[i] = a[i];
	for(ll i=3;i<n;i++)
		dp[i] = a[i] + min(dp[i-1], min(dp[i-2], dp[i-3]));

	cout << accumulate(a, a + n, (ll)0) - min(dp[n-1], min(dp[n-2], dp[n-3])) << "\n";
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