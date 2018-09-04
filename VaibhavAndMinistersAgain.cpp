#include <bits/stdc++.h>
#define SIZE 5000
#define F0(i,n) for (ll i = 0; i < n; i++)
#define F1(i,n) for (ll i = 1; i <= n; i++)
#define CL(a,x) memset(x, a, sizeof(x));
#define SZ(x) ((int)x.size())
#define mod 1000000007

using namespace std;


typedef long long ll;

ll m = 1000000007;
ll fact[SIZE];

ll power(ll a, ll b){
	ll x = 1, y = a;
	while (b > 0){
		if (b%2){
			x = ((x%mod)*(y%mod))%mod;
		}
		y = ((y%mod)*(y%mod))%mod;
		b /= 2;
	}
	return x%mod;
}


ll inverse(ll a)
{
    ll m0 = m;
    ll y = 0, x = 1;
 
    if (m == 1)
      return 0;
 
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
       x += m0;
 
    return x;
}

ll nCr(ll n, ll k){
	return (fact[n]*((inverse(fact[k]*inverse(fact[n-k]))%mod))%mod);
};


void te(){
	ll p, q, c, m;
	cin >> p >> q >> c >> m;

	ll g[m], b[m];
	for(ll i=0;i<m;i++) cin >> g[m] >> b[m];
	fact[1] = 1;
	for(ll i=2;i<SIZE;i++){
		fact[i] = ((i % mod) * fact[i-1]) % mod;
	}

	cout << nCr(p, q);
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	te();

	return 0;
}