#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll a, b, dp[110][110];
string s1, s2;

void te(){
	cin >> a >> b >> s1 >> s2;
	for(ll i=0;i<=a;i++)
		dp[i][0] = i;
	for(ll i=0;i<=b;i++)
		dp[0][i] = i;

	for(ll i=1;i<=a;i++)
		for(ll j=1;j<=b;j++){
			if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
		}


	// for(ll i=0;i<=a;i++){
	// 	for(ll j=0;j<=b;j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	cout << dp[a][b] << "\n";
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