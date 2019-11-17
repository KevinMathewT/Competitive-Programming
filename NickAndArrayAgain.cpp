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

ll n, a[100010];
unordered_map<ll, ll> m;
ll dp[100010][2];

ll DP(ll pos, ll state){
	if(pos == n-1 && state == 0)
		return a[pos];
	if(pos == n-1 && state == 1)
		return -a[pos]-1;
	if(dp[pos][state] != -1)
		return dp[pos][state];

	if(state == 0)
		return dp[pos][state] = max(a[pos] * DP(pos + 1, 0), a[pos] * DP(pos + 1, 1));
	else{
		ll x = -a[pos]-1;
		return dp[pos][state] = max(x * DP(pos + 1, 0), x * DP(pos + 1, 1));
	}

}

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];
	for(ll i=0;i<n;i++)
		dp[i][0] = dp[i][1] = -1;

	cout << max(dp[0][0], dp[0][1]) << "\n";
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