#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SIZE (100010L)

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[3][SIZE];
ll dp[SIZE][3];

ll solve(ll x, ll curr){
	if(x == n)
		return 0;

	if(dp[x][curr] != -1)
		return dp[x][curr];

	ll ans = LLONG_MIN;

		for(ll i=0;i<3;i++)
			if(i != curr)
				ans = max(ans, solve(x+1, i));

		// cout << x << " " << curr << " " << state << " " << a[curr][x] + ans << "\n";  

		return dp[x][curr] = a[curr][x] + ans;
	
}

void te(){
	cin >> n;
	for(ll i=0;i<n;i++){
		cin >> a[0][i] >> a[1][i] >> a[2][i];
		for(ll j=0;j<3;j++)
			dp[i][j] = -1;
	}

	cout << max(solve(0, 0), max(solve(0, 1), solve(0, 2))) << "\n";
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