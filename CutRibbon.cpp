#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a, b, c;
ll dp[(ll) 1e5];

ll DP(ll x){
	// cout << x << " ";
	if(x == 0) return 1;
	if(x < 0) return LLONG_MIN;
	if(dp[x] != -1) return dp[x];

	ll tot = max(DP(x-a), max(DP(x-b), DP(x-c)));

	// cout << "\n" << tot << "\n";
	return dp[x] = 1 + tot;
}


void te(){
	memset(dp, -1, (ll) 1e5);
	cin >> n >> a >> b >> c;

	cout << max(DP(n-a), max(DP(n-b), DP(n-c))) << "\n";
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