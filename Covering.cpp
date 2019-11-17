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

ll n;

void solve(){
	cin >> n;
	vector<pair<ll, ll> > p(n, {0, 0});
	for(ll i=0;i<n;i++){
		cin >> p[i].S >> p[i].F;
	}

	sort(p.begin(), p.end());

	ll minl = p[0].F, c = 1;

	for(ll i=1;i<n;i++){
		if(p[i].S > minl)
			minl = p[i].F, c++;
	}

	cout << c << "\n";
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