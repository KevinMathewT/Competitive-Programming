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

ll SIZE = 1e3 + 10;
ll MOD = 1e9 + 7;

ll modularExponentiation(ll x, ll n)
{
    ll result = 1;
    while(n > 0)
    {
        if(n % 2 == 1)
            result = ((result%MOD) * (x%MOD))%MOD;
        x = ((x%MOD) * (x%MOD))%MOD;
        n = n / 2;
    }
    return result;
}

ll mI(ll A)
{
    return modularExponentiation(A, MOD-2);
}

ll mod(ll a)
{
    ll tmp=a/MOD;
    return a-(MOD*tmp);
}

void te(){
	ll n, k, a, b;
	read(n, k, a, b);

	n--;
	ll ans = 0;
	ll x = 1, y = 1, z = 1;
	ll p = modularExponentiation(a, n), q = 1, r = k;
	for(ll i=0;i<=n;i++){
		// ans += ((((x*y) / z)%MOD) * ((((p*q)%MOD)*(r%MOD))%MOD))%MOD;
		ll part1 = mod(mod(x*y) * mI(z));
		ll part2 = mod(mod(p*q)*r);
		// cout << part1 << " " << part2 << "\n";
		ans = mod(((mod(ans)) + (mod(mod(part1) * mod(part2)))));
		ans = ans % MOD;
		// cout << "complex : " << ((((x*y) / z)%MOD) * ((((p*q)%MOD)*(r%MOD))%MOD))%MOD << "\n";
		x = mod((mod(mod(x) * mod(n+i+1)) * mI(i+1)));
		y = mod((mod(mod(y) * mod(n-i)) * mI(i+1)));
		z = mod(z + 1);
		p = a == 0 ? 0 : (mod(p / a));
		q = mod(q * b);
		r = mod(r * k);
		// cout << x << " " << y << " " << z << "\n";
		// cout << "ans - " << ans << "\n";
	}
	cout << ans << "\n";
	// cout << "-----------------\n";
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