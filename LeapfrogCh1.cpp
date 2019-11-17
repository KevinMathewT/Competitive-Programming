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

void solve(ll T){
	cin >> s;
	if(s.size() <= 2){
		cout << "Case #" << T << ": " << "N\n";
		return;
	}

	ll b = 0;
	for(ll i=0;i<s.size();i++)
		if(s[i] == 'B')
			b++;

	if(b >= ceil((ld)(s.size() - 1) / 2.0) && b < s.size() - 1)
		cout << "Case #" << T << ": " << "Y\n";
	else
		cout << "Case #" << T << ": " << "N\n";
}

int main()
{
	freopen("leapfrog_ch_.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	for(ll i=1;i<=T;i++)
		solve(i);

	return 0;
}