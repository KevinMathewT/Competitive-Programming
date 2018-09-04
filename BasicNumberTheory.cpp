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

ll modularExponentiation(ll x, ll y, ll m){
	ll result = 1;
	while(y > 0){
		if(y%2 == 1)
			result = ((result % m) * (x % m)) % m;
		x = ((x % m) * (x % m)) % m;
		y /= 2;
	}
	return result;
}

ll p = 1, q = 0;
void multiplicativeInverse(ll a, ll m){
	if(m == 0) return;
	multiplicativeInverse(m, a%m);
	ll temp = p;
	p = q;
	q = temp - ((a/m)* q);
}

void te(){
	ll a, b, c, m;
	read(a, b, c, m);
	ll d = modularExponentiation(a, b, m);
	multiplicativeInverse(c, m);
	ll e = (p % m + m) % m;
	ll f = ((d % m) * (e % m)) % m;
	cout << f << "\n";
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