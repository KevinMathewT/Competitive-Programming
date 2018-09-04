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

ll power(ll x, ll y, ll p)
{
    ll res = 1; 
    x = x % p;
    while (y > 0)
    {
    	if (y & 1)
            res = ((res) * (x)) % p;
        y = y>>1;
        x = (x * x) % p;
    }
    return res;
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll t;
	read(t);
	while(t--){
		ll k, d0, d1;
		read(k, d0, d1);
		ll r = power(2, k-1, 10) - 1;
		if(r == -1)
			r = 9;
		cout << r << "\n";
		ll a = (((d0 + d1) % 3) + (((r * ((d0 + d1) % 10)) % 10) % 3)) % 3;
		if(a == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	end_clock();							//This too.
	return 0;
}