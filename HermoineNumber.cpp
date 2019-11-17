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

ll n, a[100010], pre[100010], fact[100010], M = 1000000007;

ll pow(ll a, ll x){
	if(x == 0)
		return 1;
	if(x == 1)
		return a;
	if(x % 2 == 0)
		return pow((a * a) % M, x / 2);

	return ((pow((a * a) % M, x / 2) * a) % M);
}

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	fact[0] = 1;
	for(ll i=1;i<100010;i++)
		fact[i] = (fact[i-1] * i) % M;

	pre[0] = fact[a[0]];
	for(ll i=1;i<n;i++)
		pre[i] = (pre[i-1] * fact[a[i]]) % M;

	ll q;
	cin >> q;

	while(q--){
		ll l, r;
		cin >> l >> r;

		l--; r--;

		ll b_pow;

		if(l == 0)
			b_pow = pre[r];
		else
			b_pow = (pre[r] * (pow(pre[l-1], M - 2))) % M;

		ll final = pow(b_pow, r - l);
		if(q != 1)
			cout << final << "\n";
		else
			cout << final;
	}
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