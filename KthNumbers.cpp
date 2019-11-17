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

ll n, a[100010], f[100010], fact[100010], p2[100010], M = 1e9 + 7;
const ll maxn = 6100;
ll C[maxn + 1][maxn + 1];

ll power(ll a, ll x){
	if(x == 0) return 1;
	if(x == 1) return a;
	if(x % 2 == 0) return power((a * a) % M, x / 2);
	else return (a * power((a * a) % M, x / 2)) % M;
}

ll xCr(ll x, ll r){
	return ((fact[x] * power((fact[x - r] * fact[r]) % M, M - 2)) % M);
}

void solve(){
	cin >> n;
	for(ll i=1;i<=n;i++)
		cin >> a[i];

	fill(f, f + n + 10, 0);

	for(ll i=1;i<=n;i++)
		for(ll j=i;j<=n;j++){
			f[i] = (f[i] + (((C[j - 1][i - 1] * p2[n - j]) % M) * a[j]) % M) % M;
		}

	for(ll i=1;i<=n;i++)
		cout << f[i] << " ";
	cout << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	fact[0] = fact[1] = 1;
	for(ll i=2;i<100010;i++)
		fact[i] = (fact[i-1] * i) % M;
	p2[0] = 1;
	p2[1] = 2;
	for(ll i=2;i<100010;i++)
		p2[i] = (p2[i-1] * 2) % M;

	C[0][0] = 1;
	for (ll n = 1;n<=maxn;++n) {
	    C[n][0] = C[n][n] = 1;
	    for (ll k = 1; k < n; ++k)
	        C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % M;
	}

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}