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

	dp[0] = max((ll)0, a[0]);
	for(ll i=1;i<n;i++){
		if(i == 1){
            dp[1] = max(dp[0], a[1]);
			continue;
		}

		dp[i] = max((ll) 0, max(dp[i - 2], max(a[i], max(dp[i - 1], dp[i - 2] + a[i]))));
	}

	if(dp[n-1] <= 0){
		cout << *max_element(a, a + n) << "\n";
	}
	else
		cout << max(0, dp[n-1]) << "\n";
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