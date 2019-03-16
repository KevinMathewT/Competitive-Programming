#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, a[5010], dp[5010];
ld temp;

void te(){
	cin >> n >> m;
	for(ll i=0;i<n;i++){
		cin >> a[i] >> temp;
	}

	for(ll i=0;i<n;i++){
		if(i == 0)
			dp[i] = 1;

		dp[i] = 1;
		for(ll j=i-1;j>=0;j--)
			if(a[j] <= a[i])
				dp[i] = max(dp[i], 1 + dp[j]);
	}

	ll mx = 0;
	for(ll i=0;i<n;i++)
		mx = max(mx, dp[i]);

	cout << n - mx << "\n";
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