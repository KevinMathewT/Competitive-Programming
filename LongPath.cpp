#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, p[1010], dp[1010], cum[1010], m = 1000000007;

void te(){
	cin >> n;
	for(ll i=1;i<=n;i++)
		cin >> p[i];

	dp[0] = 0;
	cum[0] = 0;

	ll portals = 0;

	for(ll i=1;i<=n+1;i++){
		if(i == 1)
			dp[i] = 1;
		else
			dp[i] =	(((2 + ((cum[i-1] - cum[p[i]-1]) % m) + (i - p[i]) - 1)) + m) % m;
		
		cum[i] = (dp[i] + cum[i-1]) % m;
	}

	// for(ll i=0;i<=n+1;i++)
	// 	cout << dp[i] << " " ;
	// cout << "\n";

	// for(ll i=0;i<=n+1;i++)
	// 	cout << cum[i] << " " ;
	// cout << "\n";

	cout << dp[n+1] - 2 << "\n";
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