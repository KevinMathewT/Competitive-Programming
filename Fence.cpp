#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew

void te(){
	ll n, k; cin >> n >> k;
	ll a[n]; for(ll i=0;i<n;i++) cin >> a[i];
	ll dp[n];
	dp[0] = a[0];
	for(ll i=1;i<n;i++) dp[i] = dp[i-1] + a[i];

	ll pos = 1;
	ll min_val = dp[k-1];
	for(ll i=k;i<n;i++)
		if(min_val > (dp[i]-dp[i-k])){
			min_val = dp[i]-dp[i-k];
			pos = i-k+2;
		}

	// cout << min_val << "\n";
	cout << pos << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	// ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}