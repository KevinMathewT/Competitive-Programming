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
ll m = 1e9+7;
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

void te(){
	ll n, k, a, b;
	read(n, k, a, b);
	ll npkCk[n+5], nCk[n+5];
	n--;
	npkCk[0] = 1;
	nCk[0] = 1;
	for(ll i=1;i<=n;i++)
		npkCk[i] = ((npkCk[i-1] % m * (((n+i) * (n-i+1)) / ((2*i)*(2*i-1))))) % m;
	for(ll i=1;i<=n;i++)
		nCk[i] = (nCk[i-1] % m * (((2 * (2*i-1)) / (i+1)))) % m;
	
	// for(ll i=0;i<=n;i++)
	// 	cout << npkCk[i]*nCk[i] << " ";
	// cout << "\n";
	ll ans = 0;
	for(ll i=0;i<=n;i++){
		ans = ((ans%m) + (((((((((nCk[i] * npkCk[i])%m) * (power(a, n-i)))%m) * power(b, i))%m) * power(k, i+1)))%m)) % m;
	}

	cout << ans << "\n";
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