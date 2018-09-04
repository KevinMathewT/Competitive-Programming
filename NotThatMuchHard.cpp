#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned long long ll;
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

ll m = 1000000007;

ll fastexp(ll k, ll p){
	ll res = 1;
	ll x = k % m;
	while(p > 0){
		if(p % 2 == 1)
			res = ((res % m) * (x % m) % m);
		x = ((x % m)*(x % m) % m);
		p /= 2;
	}
	return res;
}

void te(){
	ll n, k;
	read(n, k);
	// if(n == 0){ cout << 0 << "\n"; return; }
	// if(n == 1){ cout << k << "\n"; return; }
	cout << (((((((n*(n-1)) % m) % m) * (((k % m)*(k % m)) % m)) % m) * (fastexp(k+1, n-2)) % m) % m) + (((n*k) % m)*(fastexp(k+1, n-1)) % m);
}

ll cost[] = {12, 66, 88, 123, 66, 231};

ll solve(ll L, ll R, ll val)
{
    if(L == R+1){
    	cout << val << "\n";
        return val;
    }
    return solve(L+1,R,val) + solve(L+1,R,val*cost[L-1]);
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// read(T);
	// while(T--) te();

	cout << solve(2, 3, 1) << "\n";

	end_clock();							//This too.
	return 0;
}