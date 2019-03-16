#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[((ll)(1e5 + 10L))], dp[((ll)(1e5 + 10L))];

ll solve(ll x){
	if(x == n-1)
		return 0;
	if(x > n-1)
		return 9999999999999;
	if(dp[x] != -1)
		return dp[x];

	return dp[x] = min(abs(a[x]-a[x+1]) + solve(x+1), abs(a[x]-a[x+2]) + solve(x+2));
}

void te(){
	cin >> n;
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