#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define INF 1000010
#define M 1000000007

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, k, sieve[INF];

ll power(ll a, ll x){
	if(x == 0) return 1;
	if(x == 1) return a;
	if(x % 2 == 0) return power((a * a) % M, x / 2);
	return (a * power((a * a) % M, x / 2)) % M;
}

void solve(){
	cin >> n >> k;
	ll prod = power((k % M), sieve[n]);
	cout << prod << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	fill(sieve, sieve + INF, 1);
	sieve[0] = 0;
	sieve[1] = 0;
	for(ll i=2;i<INF;i++)
		if(sieve[i] == 1)
			for(ll j=2*i;j<INF;j+=i)
				sieve[j] = 0;

	for(ll i=1;i<INF;i++)
		sieve[i] = (sieve[i] + sieve[i-1]) % M;

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}