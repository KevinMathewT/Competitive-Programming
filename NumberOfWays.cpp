#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n;
	cin >> n;
	ll a[n];
	for(ll i=0;i<n;i++) cin >> a[i];

	ll dp[n];
	dp[0] = a[0];
	for(ll i=1;i<n;i++)
		dp[i] = a[i] + dp[i-1];

	if(dp[n-1] % 3 != 0){
		cout << 0 << "\n";
		return;
	}

	ll x = dp[n-1] / 3;
	ll tot = 0;
	ll count = 0;

	for(ll i=n-2;i>=0;i--){
		if(dp[i] == x)
			tot += count;
		if(dp[i] == 2 * x)
			count++;
	}

	cout << tot << "\n";
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