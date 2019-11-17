#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew
// LinkedIn - https://www.linkedin.com/in/KevinMathewT

ll n, fib[100];

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	fib[0] = 0;
	fib[1] = 1;

	for(ll i=2;i<60;i++)
		fib[i] = fib[i-1] + fib[i-2];
	for(ll i=0;i<60;i++){
		fib[i] = fib[i] % 10;
	}

	ll T;
	cin >> T;
	while(T--){
		cin >> n;
		// ll t = n;
		// cin >> n;
		// n = (((ll) pow(2, (ll)log2(n))) - 1) % 60;

		ll pos = 0;
		while (n >>= 1) ++pos;
		// cout << pos << "--\n";
		n = ((ll) pow(2, pos) - 1) % 60;

		cout << fib[n] << "\n";
	}

	return 0;
}