#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n;
string s;
ll occur[50], poin, dp[100010][50];

void te(){
	for(ll i=0;i<100010;i++)
		for(ll j=0;j<=26;j++)
			dp[i][j] = 0;

	poin = 0;
	char new_s[26];

	cin >> n >> s;
	for(ll i=0;i<=26;i++)
		occur[i] = 0;

	for(ll i=0;i<s.size();i++){
		if(occur[s[i]-'a'] != 1){
			new_s[poin++] = s[i];
			occur[s[i]-'a'] = 1;
		}
	}

	for(ll i=0;i<=poin;i++)
		dp[0][i] = 0;
	for(ll i=0;i<=n;i++)
		dp[i][0] = 1;

	// for(ll i=0;i<poin;i++)
	// 	cout << new_s[i] << "";
	// cout << "\n";

	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=poin;j++){
			if(s[i-1] == new_s[j-1]){
				dp[i][j] =  (dp[i-1][j] + dp[i-1][j-1]) % 1000000007;
			}
			else
				dp[i][j] = dp[i-1][j]; 
		}

	// for(ll i=0;i<=s.size();i++){
	// 	for(ll j=0;j<=poin;j++)
	// 		cout << dp[i][j] << " " ;
	// 	cout << "\n";
	// }

	cout << dp[s.size()][poin] << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}