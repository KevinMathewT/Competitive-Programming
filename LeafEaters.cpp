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

ll n, k, d[100];

void solve(){
	cin >> n >> k;
	n--;
	for(ll i=0;i<k;i++)
		cin >> d[i];

	ll tot = 0;

	for(ll i=1;i<(1<<k);i++){
		ll pr = 1, p = 0;
		for(ll j=0;j<k;j++)
			if(i & (1 << j))
				p ^= 1, pr = pr / __gcd(pr, d[j]) * d[j];

		if(p == 1)
			tot += n / pr;
		else
			tot -= n / pr;
	}

	cout << (n - tot) << "\n";
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