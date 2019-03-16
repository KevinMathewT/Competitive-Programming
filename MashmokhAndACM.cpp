#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, k, dp[2010][2010];

ll solve(ll a, ll b){
	// cout << a << " " << b << "\n";

	if(a > n) return 0;
	if(b <= 1) return 1;
	if(dp[a][b] != -1){
		// cout << "YAY\n";
		return dp[a][b];
	}

	ll ways = 0;

	for(ll i=1;i<=n && (a*i <= n);i++)
			ways = ((ways) + (solve(a * i, b - 1))) % MOD;

	return dp[a][b] = ways;
}

void te(){
	cin >> n >> k;
	for(ll i=0;i<2010;i++)
		for(ll j=0;j<2010;j++)
			dp[i][j] = -1;

	ll ans = 0;

	for(ll i=1;i<=n;i++)
		ans = ((ans) + (solve(i, k))) % MOD;

	cout << ans << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}