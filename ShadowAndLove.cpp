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

ll a, b, l, r;

ll divisible(ll x, ll y, ll z){
	return (y / z) - (x / z);
}

void solve(){
	cin >> a >> b >> l >> r;

	ll p = divisible(l, r, a);
	ll q = divisible(l, r, b);
	ll r = divisible(l, r, (a * b) / __gcd(a, b));

	bool s = false, t = false;

	if((p + q - r) % 2 == 0)
		s = true;
	if((p + q) % 2 == 0 || (p + q) % 3 == 0)
		t = true;

	if(s && t){
		cout << "TRUE LOVE\n";
		return;
	}

	if(s || t){
		cout << "LOVE\n";
		return;
	}

	cout << "FAKE LOVE\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}