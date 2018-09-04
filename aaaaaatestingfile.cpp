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

ll gcd(ll a, ll b);
ll power(ll x,  ll y,  ll m);
ll modInverse(ll a, ll m)
{
    return power(a, m-2, m);
}

ll power(ll x,  ll y,  ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m;
 
    return (y%2 == 0)? p : (x * p) % m;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("input1.txt", "w", stdout);		//this
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	cout << 50000 << "\n";

	for(ll i=1;i<(50000/5);i++){
		cout << "abcd\nabcc\nabb\nasdl\ndsad\n";
	}

	cout << "abcd\nabcc\nabb\nasdl\nabcdex\n";

	cout << 99999 << "\n";

	for(ll i=0;i<99999/3;i++){
		cout << "50000 a\n50000 aksjd\n50000 abcdex\n";
	}
	
	end_clock();

	cout << "Hey\n";
	return 0;
}