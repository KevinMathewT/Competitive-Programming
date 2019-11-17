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

ll x, y;
string s;

void solve(){
	cin >> x >> y;
	cin.ignore(256, '\n');
	cin >> s;

	for(ll i=0;i<s.size();i++){
		if(s[i] == 'U')
			y++;
		if(s[i] == 'D')
			y--;
		if(s[i] == 'L')
			x--;
		if(s[i] == 'R')
			x++;
	}

	cout << x << " " << y << "\n";
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