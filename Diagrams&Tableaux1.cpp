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

ll k, tot, l[10], n, dp[10][10], lastx, lasty;
map<ll, ll> dp1;

ll rec(ll x, ll y, ll state){
	if(x == k && y == l[k-1]-1){
		// cout <<	"--------------\n";
		// for(ll i=0;i<k;i++){
		// 	for(ll j=0;j<l[i];j++)
		// 		cout << dp[i][j] << " ";
		// 	cout << "\n";
		// }
		// cout << "--------------\n";
		return dp1[x][y] = 1;
	}

	if(dp1[x][y] != -1)
		return dp1[x][y];

	if(x == 0 && y == 0){
		// cout << x << " " << y << "-\n";
		ll ret = 0;
		for(ll i=0;i<n;i++){
			dp[x][y] = i;
			if((y + 1) < l[x])
				ret += rec(x, y + 1);
			else
				ret += rec(x + 1, 0);
		}
		return dp1[x][y] = ret;
	}

	if(x == 0){
		// cout << x << " " << y << "--\n";
		ll ret = 0;
		for(ll i=dp[x][y-1];i<n;i++){
			dp[x][y] = i;
			if((y + 1) < l[x])
				ret += rec(x, y + 1);
			else
				ret += rec(x + 1, 0);
		}
		return dp1[x][y] = ret;
	}

	if(y == 0){
		// cout << x << " " << y << "---\n";
		ll ret = 0;
		for(ll i=dp[x-1][y]+1;i<n;i++){
			dp[x][y] = i;
			if((y + 1) < l[x])
				ret += rec(x, y + 1);
			else
				ret += rec(x + 1, 0);
		}
		return dp1[x][y] = ret;
	}

	// cout << x << " " << y << "----\n";
	ll ret = 0;
	for(ll i=max(dp[x-1][y] + 1, dp[x][y-1]);i<n;i++){
		dp[x][y] = i;
		if((y + 1) < l[x])
			ret += rec(x, y + 1);
		else
			ret += rec(x + 1, 0);
	}
	return dp1[x][y] = ret;
}

void solve(){
	fill(l, l + 10, 0);
	for(ll i=0;i<10;i++)
		for(ll j=0;j<10;j++)
			dp1[i][j] = -1;
	tot = 0;
	for(ll i=0;i<k;i++)
		cin >> l[i];
	cin >> n;

	if(k == 1 && l[0] == 1){
		cout << n << "\n";
		return;
	}

	cout << rec(0, 0) << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	while(cin >> k)
		solve();

	return 0;
}