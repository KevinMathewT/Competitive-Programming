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
#define SZ(x) ((int)x.size())

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

ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

ll power(ll x,  ll y,  ll m){
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m;
 
    return (y%2 == 0)? p : (x * p) % m;
}

ll modInverse(ll a, ll m){
    return power(a, m-2, m);
}

void te(){
	ll n, w; read(n);
	w = n;
	if(n % 2 == 0) w = n - 1;

	ll powr = power(26, w/2, 1000000007);
	ll a = (2 * (powr-1)) % 1000000007;
	ll b = modInverse((powr * 25) % 1000000007, 1000000007);
	ll ans = (1 + ((a * b) % 1000000007)) % 1000000007;

	if(n % 2 == 0)
		ans = ((ans % 1000000007) + modInverse((ll) power(26, n/2, 1000000007), 1000000007)) % 1000000007;
	cout << ans <<  "\n";;
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll t; read(t);
	while(t--) te();

	end_clock();							//This too.
	return 0;
}