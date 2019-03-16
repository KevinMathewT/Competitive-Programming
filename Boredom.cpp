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

	ll size = (ll) *max_element(a, a+n);
	ll dp[size+1];

	unordered_map<ll, ll> um;

	for(ll i=0;i<n;i++)
		um[a[i]]++;

	dp[0] = 0;
	dp[1] = um[1];
	for(ll i=2;i<=size;i++){
		// cout << i << " " << i*um[i] << " " << dp[i-2] << " " << dp[i-1] << "\n";
		dp[i] = max(i*um[i] + dp[i-2], dp[i-1]);
	}

	// cout << size << "\n";
	cout << dp[size] << "\n";
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