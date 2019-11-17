#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define M 1000000007

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll power(ll x, ll a){
	if(a == 0) return 1;
	if(a == 1) return x;
	if(a % 2 == 0) return power((x * x) % M, a / 2);
	return (x * (power((x * x) % M, a / 2))) % M;
}

ll n, c;

ll getburn(ll x){
	// cout << x << " ";
	ll p = (power(x, 4) + power(x, 2)) % M;
	ll q = (p + power(x, 1)) % M;
	ll r = (q + power(x, 1)) % M;
	ll s = (r * power(4, M - 2)) % M;
	// cout << p << ' ' << q << " " << r << " " << s << "\n";
	return s;
}

void solve(){
	cin >> n >> c;
	if(n % 2 == 0){
		ll z = (getburn(power(power(c, (n / 2) * 5), (n / 2))));
		// cout << y << " " << z << "\n";
		cout << (z % M) << "\n";
	}
	else{
		ll p = (n + 1) / 2;
		ll q = (n - 1) / 2;
		ll x = (power(power(c, p), q) * power(power(c, n), n)) % M;
		ll z = (c * getburn(x)) % M;

		cout << z << "\n";
	}
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