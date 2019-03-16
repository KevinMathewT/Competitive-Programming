#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, dp[100010];

void te(){
	cin >> n;
	for(ll i=0;i<n;i++){
		ll q;
		cin >> q;

		for(ll j=1;j<=q;j++)
			dp[j] = -1;

		dp[1] = dp[5] = dp[7] = dp[11] = 1;

		for(ll j=1;j<=q;j++){
			if(dp[j] == -1){
				if(j > 1)
					dp[j] = 1 + dp[j-1];
				if(j > 5)
					dp[j] = min(dp[j], 1 + dp[j-5]);
				if(j > 7)
					dp[j] = min(dp[j], 1 + dp[j-7]);
				if(j > 11)
					dp[j] = min(dp[j], 1 + dp[j-11]);
			}

			// cout << dp[j] << " ";
		}
		// cout << "\n";

		cout << dp[q] << "\n";
	}
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

		te();

	return 0;
}