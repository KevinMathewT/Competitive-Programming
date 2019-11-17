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

ll n;
string s;

void solve(){
	cin >> n;
	cin >> s;

	ll a = 0, b = 0, c = 0, d = 0, e = 0;

	for(ll i=0;i<s.size();i++)
		if(s[i] == 'a')
			a++;
		else if(s[i] == 'b')
			b++;
		else if(s[i] == 'c')
			c++;
		else if(s[i] == 'd')
			d++;
		else if(s[i] == 'e')
			e++;

	cout << min(a, min(b, min(c, min(d, e)))) << " ";
	cout << max(a, max(b, max(c, max(d, e)))) << "\n";
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