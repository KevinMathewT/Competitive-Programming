#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[1010], dp[1010];

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];
	for(ll i=0;i<n;i++)
		dp[i] = 1;
	for(ll i=1;i<n;i++)
		for(ll j=0;j<i;j++)
			if(a[j] < a[i])
				dp[i] = max(dp[i], 1 + dp[j]);

	cout << *max_element(dp, dp + n) << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}