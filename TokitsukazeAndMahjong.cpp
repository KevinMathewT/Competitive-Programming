#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

string s[3];
vector<pair<char, ll> > v;

void solve(){
	cin >> s[0] >> s[1] >> s[2];
	for(ll i=0;i<3;i++)
		v.push_back(make_pair(s[i][1], stoll(s[i].substr(0, 1))));

	sort(v.begin(), v.end());

	ll ans1 = 2;

	for(ll i=1;i<3;i++)
		if(v[i] == v[i-1])
			ans1--;

	ll ans2 = 2;

	for(ll i=1;i<3;i++)
		if((v[i].F == v[i-1].F) && (v[i].S == (v[i-1].S + 1)) && (((v[i].S + 2) <= 9) || ((v[i].S - 1) >= 1)))
			ans2--;

	cout << min(ans1, ans2);
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