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

ll n, a[100010], M;
unordered_map<ll, ll> m;

ll power(ll x, ll a){
	if(a == 0) return 1;
	if(a == 1) return x;
	if(a % 2 == 0) return power((x * x) % M, a / 2);
	return (x * power((x * x) % M, a / 2)) % M;
}

void solve(){
	M = 1e9 + 7;
	cin >> n;
	for(ll i=0;i<n;i++) cin >> a[i];

	for(ll i=0;i<n;i++) m[a[i]]++;

	ll tot = 0;
	
	for(ll i=1;i<=100000;i++)
		tot = (tot + power(2, m[i]) - 1 + M) % M;

	cout << tot << "\n";
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