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

ll n, a, b, l1, l2;

void solve(){
	a = 0, b = 0, l1 = 0, l2 = 0;
	cin >> n;

	for(ll i=0;i<n;i++){
		ll u, v; cin >> u >> v;
		a += u; b += v;
		if((a > b) && (a - b) > l2)
			l1 = 1, l2 = (a - b);
		if((b > a) && (b - a) > l2)
			l1 = 2, l2 = (b - a);
	}

	cout << l1 << ' ' << l2 << "\n";
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