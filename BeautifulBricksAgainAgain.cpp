#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

map<ll, map<ll, ll> > dp;

ll recur(ll n, ll k){
	if(dp[n][k] != 0) return dp[n][k];
	if(k == 1) return n;
	if(k == n) return 1;
	return dp[n][k] = recur(n-2, k-1) + recur(n-1, k-1) + recur(n-1, k);
}

void te(){
	ll n, k;
	cin >> n >> k;
	for(ll i=0;i<=10;i++){
		for(ll j=1;j<=10;j++){
			if(j-i > 0)
				cout << recur(j, j-i) << ",";
		}
		cout << "\n";
	}
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