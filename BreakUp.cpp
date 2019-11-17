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

ll n, a[310], dp[310];

bool isPalin(ll x, ll y){
	ll len = (y - x) + 1;
	bool ret = true;

	for(ll i=x;i<x+len;i++)
		if(a[i] != a[x+len-i+x-1])
			ret = false;

	return ret;
}

void solve(){
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];

	dp[0] = 0;
	for(ll i=1;i<=n;i++)
		dp[i] = 1 + dp[i-1];

	for(ll i=2;i<=n;i++){
		for(ll j=i;j>0;j--){
			if(isPalin(j, i)){
				dp[i] = min(dp[i], dp[j-1] + 1);
			}
		}
	}

	// for(ll i=0;i<=n;i++)
	// 	cout << dp[i] << " ";
	// cout << "\n";

	cout << dp[n] << "\n";
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