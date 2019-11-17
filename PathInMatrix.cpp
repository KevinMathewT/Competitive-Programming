#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[50][50], dp[50][50];

void te(){
	cin >> n;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			cin >> a[i][j];

	for(ll i=0;i<=n;i++){
		dp[0][i] = -LLONG_MAX;
		dp[i][0] = -LLONG_MAX;
	}

	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(i == 1)
				dp[i][j] = a[i][j];
			else{
				dp[i][j] = a[i][j] + max(dp[i-1][j], max(dp[i-1][j-1], dp[i-1][j+1]));
			}
		}
	}

	// for(ll i=0;i<=n;i++){
	// 	for(ll j=0;j<=n;j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << "\n";
	// }

	cout << *max_element(dp[n], dp[n] + n) << "\n";
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