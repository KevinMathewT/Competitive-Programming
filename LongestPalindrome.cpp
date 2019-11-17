#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, dp[5010][5010], b, l, r;
string s;

void solve(){
	b = 1, l = 0, r = 1;
	cin >> n >> s;

	for(ll i=1;i<=n;i++)
		for(ll j=0;(j+i-1)<n;j++){
			if(i == 1)
				dp[i][j] = 1;
			else if(i == 2)
				dp[i][j] = (s[j] == s[j + i - 1]);
			else
				dp[i][j] = (s[j] == s[j + i - 1]) & (dp[i-2][j+1]);

			if(dp[i][j] & (i > b))
				b = i, l = j, r = i;
		}

	cout << b << "\n";
	cout << s.substr(l, r) << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}