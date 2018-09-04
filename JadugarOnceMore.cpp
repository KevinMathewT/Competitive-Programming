#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define F0(i,n) for (ll i = 0; i < n; i++)
#define F1(i,n) for (ll i = 1; i <= n; i++)
#define CL(a,x) memset(x, a, sizeof(x));
#define SZ(x) ((ll)x.size())

void read(ll &x){
	cin >> x;
}
void read(ll &x,ll &y){
	cin >> x >> y;
}
void read(ll &x,ll &y,ll &z){
	cin >> x >> y >> z;
}
void read(ll &x,ll &y,ll &z,ll &w){
	cin >> x >> y >> z >> w;
}
clock_t t_start,t_end;
void start_clock(){
	t_start = clock();
}
void end_clock(){
	t_end = clock();
	ld timeis = t_end - t_start;
    printf("\n\nTime taken : %f s", ((float)timeis)/CLOCKS_PER_SEC);
}

bool IsOdd(ll n){ return n % 2 == 1; }

ll m = 1e9 + 7;
ll gcd(ll a, ll b);
ll power(ll x, ll y);
ll modInverse(ll a)
{
    return power(a, m-2);
}
ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2) % m;
    p = (p * p) % m;
 
    return (y%2 == 0)? p : (x * p) % m;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

ll binomialCoeff(ll n, ll k)
{
    ll res = 1;
    if (k > n - k)
        k = n - k;
    for (ll i = 0; i < k; ++i)
    {
        res = (res * (n - i)) % m;
        res = (res * modInverse(i + 1)) % m;
    }
    return res;
}

ll catalan(ll n)
{
    ll c = binomialCoeff(2*n, n);
    return (c * modInverse(n+1)) % m;
}

void te(){
	ll n, k, c, b; read(n, k, c, b);
	ll a[n+1][n+1];
	for(ll i=0;i<=n;i++)
		for(ll j=0;j<=n;j++)
			a[i][j] = 0;
	a[1][1] = k % m;
	ll ans = 0;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=i;j++)
			if(!(i==1 && j==1))
				a[i][j] = ((((((c % m)*(a[i-1][j-1] % m)) % m) + (((k % m)*(a[i-1][j] % m)) % m)) % m) + (((b % m)*(a[i][j-1] % m)))) % m;
	ll d[n+1];
	d[0] = 0;
	for(ll i=1;i<=n;i++){
		// cout << a[i][i] << "\n";
		d[i] = ((d[i-1]%m) + ((a[i][i]*a[i][i]) % m)) % m;
	}
	ll q;
	read(q);
	while(q--){
		ll l, r;
		read(l, r);
		cout << (((d[r] - d[l-1]) + m ) % m) << "\n";
	}
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	end_clock();							//This too.
	return 0;
}