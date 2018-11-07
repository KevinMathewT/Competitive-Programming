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
	dp[1] = a[1];

	for(ll i=2;i<n;i++)
		dp[i] = max(dp[i-1], a[i] + dp[i-2]);

	if(n == 1)
		cout << a[0] << "\n";
	else
		cout << max(dp[n-2], dp[n-1]) << "\n";
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