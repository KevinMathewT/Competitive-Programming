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

ll mod(ll a){
	if(a >= 1000000007){
		cout << "WOW\n"; 
		return a % 1000000007;
	}
	return a;
}

void te(){
	ll m, n; read(m, n);
	ll a[m], b[m];
	for(ll i=0;i<m;i++) read(a[i]);
	for(ll i=0;i<m;i++) read(b[i]);

	// for(ll i=0;i<m;i++) cout << a[i] << " - " << b[i] << "\n";

	if(n == 1){
		ll s = 0;
		for(ll i=0;i<m;i++) s = mod(s + mod(m * a[i]));
		cout << s << "\n";
		return;
	}

	if(n == 2){
		ll s = 0;
		for(ll i=0;i<m;i++) s = mod(s + mod(m * b[i]));
		cout << s << "\n";
		return;
	}

	ll contria[m], contrib[m];

	ll mina = a[0];
	ll minb = b[0];
	for(ll i=0;i<m;i++){
		mina = min(mina, a[i]);
		minb = min(minb, b[i]);
	}

	for(ll i=0;i<m;i++){
		contria[i] = mod(mod((mod(a[i]-mina+1000000007)) * ((n - 3) < 1 ? 1 : n - 3)) * m);
		contrib[i] = mod(mod((mod(b[i]-minb+1000000007)) * (n - 2)) * m);
		// cout << contria[i] << " " << contrib[i] << "\n";
	}

	ll x = mina, y = minb;
	ll ans = y;
	for(ll i=3;i<=n;i++){
		ans = mod(x + y);
		x = y;
		y = ans;
	}

	ll result = 0;

	for(ll i=0;i<m;i++)
		result += mod(mod((m * ans) + (contria[i])) + contrib[i]);

	cout << result << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	read(T);
	while(T--) te();

	end_clock();							//This too.
	return 0;
}