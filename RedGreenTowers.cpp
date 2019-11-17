#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll r, g, h, dp1[200010], dp2[200010];

// ll DP(ll hc, ll rc){
// 	ll gc = g - (h * (h + 1) / 2) + (hc * (hc + 1) / 2) + r - rc;
// 	if(rc < 0 || gc < 0)
// 		return 0;
// 	if(dp[hc][rc] != -1)
// 		return dp[hc][rc];
// 	if(hc == 0)
// 		return dp[hc][rc] = 1;

// 	return dp[hc][rc] = ((DP(hc-1, rc-hc) + DP(hc-1, rc))) % 1000000007;
// }

ll checkCond(ll hc, ll rc){
	ll gc = g - (h * (h + 1) / 2) + (hc * (hc + 1) / 2) + r - rc;
	if(rc < 0 || gc < 0)
		return 0;
	return 1;
}

void te(){
	cin >> r >> g;
	h = (-1 + (sqrt(1 + 8 * (r + g)))) / 2;
	// for(ll i=0;i<900;i++)
	// 	for(ll j=0;j<200010;j++)
	// 		dp[i][j] = -1;

	for(ll hc=0;hc<=h;hc++){
		for(ll rc=0;rc<=r;rc++){
			if(hc == 0){
					dp1[rc] = 1;
				continue;
			}
			ll up = 0;
			if(checkCond(hc-1, rc))
				up = (up + dp1[rc]) % (ll)(1e9 + 7);
			if(checkCond(hc-1, rc-hc))
				up = (up + dp1[rc-hc]) % (ll)(1e9 + 7);
			dp2[rc] = up;
		}

		for(ll rc=0;rc<=r;rc++){
			if(hc == 0)
				break;
			dp1[rc] = dp2[rc];
			// cout << dp1[rc] << " ";
		}
		// cout << "\n";
	}

	cout << dp1[r] << "\n";
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