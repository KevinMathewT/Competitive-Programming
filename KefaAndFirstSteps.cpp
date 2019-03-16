#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n;
	cin >> n;
	ll a[n];
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll dp[n];
	dp[0] = 1;

	for(ll i=1;i<n;i++)
		if(a[i] >= a[i-1])
			dp[i] = dp[i-1] + 1;
		else
			dp[i] = 1;

	cout << *max_element(dp, dp+n) << "\n";
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