#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n;
ld a[3010];
ld dp[3010][3010];

ld solve(ll x, ll rem){
	// cout << x << " " << rem << "\n";
	if(x == n){
		return 1.0;
	}
	if(dp[x][rem] != -1.0)
		return dp[x][rem];

	if(rem > 0)
		return dp[x][rem] = (1-a[x]) * solve(x+1, rem-1) + (a[x]) * solve(x+1, rem);
	else
		return dp[x][rem] = (a[x]) * solve(x+1, rem);
}

void te(){
	cin >> n;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++)
			dp[i][j] = -1.0;
		cin >> a[i];
	}

	cout << solve(0, ((n/2))) << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.
	cout << fixed << setprecision(10);

	te();

	return 0;
}