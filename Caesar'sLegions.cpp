#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 100000000

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n1, n2, k1, k2, dp[110][110][15][15];

ll DP(ll f, ll h, ll consF, ll consH){
	// cout << f << " " << h << " " << consF << " " << consH << "\n";
	if(f > n1 || h > n2 || consF > k1 || consH > k2) return 0;
	if(f == n1 && h == n2)
		return 1;
	if(dp[f][h][consF][consH] != -1)
		return dp[f][h][consF][consH];

	ll ways = 0;

	if(f == n1)
		ways = ((ways) + DP(f, h+1, 0, consH+1)) % MOD;
	else if(h == n2)
		ways = ((ways) + DP(f+1, h, consF+1, 0)) % MOD;
	else if(consF == k1)
		ways = ((ways) + DP(f, h+1, 0, 1)) % MOD;
	else if(consH == k2 || h == n2)
		ways = ((ways) + DP(f+1, h, 1, 0)) % MOD;
	else{
		ways = ((ways) + DP(f+1, h, consF+1, 0)) % MOD;
		ways = ((ways) + DP(f, h+1, 0, consH+1)) % MOD;
	}

	return dp[f][h][consF][consH] = ways;
}

void te(){
	cin >> n1 >> n2 >> k1 >> k2;
	for(ll i=0;i<110;i++)
		for(ll j=0;j<110;j++)
			for(ll k=0;k<15;k++)
				for(ll l=0;l<15;l++)
					dp[i][j][k][l] = -1;

	cout << DP(0, 0, 0, 0) << "\n";
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