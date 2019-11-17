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

string s;
ll n, dp1[100010], dp2[100010];

void solve(){
	cin >> s;
	n = s.size();

	for(ll i=0;i<n;i++){
		if(i == 0)
			dp1[i] = (s[i] <= 'Z') ? 0 : 1;
		else
			dp1[i] = dp1[i-1] + ((s[i] <= 'Z') ? 0 : 1);
		// cout << dp1[i] << " ";
	}
	// cout << "\n";

	for(ll i=n-1;i>=0;i--)
		if(i == n-1)
			dp2[i] = (s[i] >= 'a') ? 0 : 1;
		else
			dp2[i] = dp2[i+1] + ((s[i] >= 'a') ? 0 : 1);

	ll mn = min(dp2[0], dp1[n-1]);
	for(ll i=0;i<n-1;i++)
		mn = min(mn, dp2[i+1] + dp1[i]);

	cout << mn << "\n";
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