#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll dp[3010][3010];
vector<char> v;

void te(){
	string s, t;
	cin >> s >> t;

	cout << s << " " << t << "\n";

	for(ll i=0;i<s.size();i++)
		dp[i][0] = 0;
	for(ll i=0;i<t.size();i++)
		dp[0][i] = 0;

	for(ll i=1;i<=s.size();i++)
		for(ll j=1;j<=t.size();j++){
			if(s[i-1] == t[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}


	ll i = s.size(), j = t.size();
	cout << s[i-1] << " " << t[j-1] << "\n";

	while(i >= 0 && j >= 0){
		cout << s[i-1] << " " << t[j-1] << "\n";		
		// if(s[i-1] == t[j-1]){
			// v.push_back(s[i-1]);
			// i--; j--;
		// }

		i--; j--; 
	}

	// for(ll i=0;i<v.size();i++)
	// 	cout << v[i]; 
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