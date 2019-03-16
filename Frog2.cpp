#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, k, a[((ll)(1e5 + 10L))], dp[((ll)(1e5 + 10L))];

ll solve(ll x){
	// cout << x << "-\n";
	if(x == n-1)
		return 0;
	if(x > n-1)
		return 9999999999999;
	if(dp[x] != -1)
		return dp[x];

	ll ans = LLONG_MAX;

	for(ll i=1;i<=k;i++)
		if(x + i < n)
			ans = min(ans, abs(a[x]-a[x+i]) + solve(x+i));

	// cout << ans << " " << x << "\n";
	return dp[x] = ans;
}

void te(){
	cin >> n >> k;
	for(ll i=0;i<n;i++){
		cin >> a[i];
		dp[i] = -1;
	}

	cout << solve(0) << "\n";
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