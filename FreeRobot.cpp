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

ll dp[20][20][20], vis[20][20], n;

ll DP(ll x, ll y, ll k){
	if(x >= n + 1 || y >= n + 1 || x < 0 || y < 0 || vis[x][y] == 1)
		return 0;
	if(k == 0)
		return 1;
	if(dp[x][y][k] != -1)
		return dp[x][y][k];
	vis[x][y] = 1;
	dp[x][y][k] = DP(x + 1, y, k - 1) + DP(x, y + 1, k - 1) + 
		   DP(x - 1, y, k - 1) + DP(x, y - 1, k - 1) + 
		   DP(x + 1, y + 1, k - 1) + DP(x - 1, y - 1, k - 1) + 
		   DP(x + 1, y - 1, k - 1) + DP(x - 1, y + 1, k - 1);
	vis[x][y] = 0;
	return dp[x][y][k];
}

void solve(){
	cin >> n;
	ll vis[20][20];
	for(ll i=0;i<20;i++)
		for(ll j=0;j<20;j++){
			vis[i][j] = 0;
			for(ll k=0;k<20;k++)
				dp[i][j][k] = -1;
		}
	cout << DP(0, 0, n) << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}