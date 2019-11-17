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

ll n, x[100010], h[100010], dp[100010][3];

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> x[i] >> h[i];

	if(n == 1){
		cout << h[0] << "\n";
		return;
	}

	for(ll i=0;i<n;i++){
		if(i == 0){
			dp[i][0] = h[i];
			dp[i][1] = 0;
			dp[i][2] = (x[i+1] - x[i]) > h[i] ? h[i] : 0;
			continue;
		}

		if(i == n-1){
			dp[i][0] = (x[i] - x[i-1]) > h[i] ? h[i] : 0;;
			dp[i][1] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
			dp[i][2] = h[i]
			continue;
		}

		if()
	}
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