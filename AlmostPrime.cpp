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

ll n, sieve[4000], pfact[4000];

void solve(){
	cin >> n;
	for(ll i=0;i<4000;i++)
		sieve[i] = i;
	for(ll i=2;(i*i)<=n;i++)
		if(sieve[i] == i)
			for(ll j=(i * i);j<=n;j+=i)
				sieve[j] = i;

	ll c = 0;

	for(ll i=6;i<=n;i++){
		fill(pfact, pfact + 4000, 0);

		ll t = i;
		while(t > 1){
			pfact[sieve[t]] = 1;
			t /= sieve[t];
		}

		if(accumulate(pfact, pfact + 4000, (ll) 0) == 2)

		c++;
	}

	cout << c << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}