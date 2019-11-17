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

string a, b;
ll ac[26], bc[26];

void solve(){
	cin >> a >> b;
	for(ll i=0;i<26;i++)
		ac[i] = bc[i] = 0;
	for(ll i=0;i<a.size();i++)
		ac[a[i] - 'a']++;
	for(ll i=0;i<a.size();i++)
		bc[b[i] - 'a']++;

	ll tot = 0;
	for(ll i=0;i<26;i++)
		tot += abs(ac[i] - bc[i]);

	cout << (tot / 2) << "\n";
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
		solve();

	return 0;
}