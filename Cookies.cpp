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

ll n, dp[1010];

ll rec(ll x){
	if(dp[x] != -1)
		return dp[x];
	return dp[x] = ((3 * rec(x - 1))) % 1000003;
}

void solve(){
	for(ll i=0;i<1010;i++)
		dp[i] = -1;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 3;
	cin >> n;
	cout << (rec(n)) << "\n";
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