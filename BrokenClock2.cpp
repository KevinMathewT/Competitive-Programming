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

ll gcd(ll a ,ll b)
{
   if(b==0) return a;
   a %= b;
   return gcd(b, a);
}

pair<ll, ll> dp[1000000+10];
int v[1000000+10];
pair<ll, ll> p0;
pair<ll, ll> p1;
pair<ll, ll> p2;

ll n1, n2, d1, d2, n, d, hcf;

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}


ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    ll res = (x % m + m) % m;
    return res;
}

pair<ll, ll> DP(ll t){
	if(v[t] == 1)
		return dp[t];
	if(t == 1)
		return p1;
	if(t == 2){
		return p2;
	}
	pair<ll, ll> t1 = DP(t-1);
	pair<ll, ll> t2 = DP(t-2);
	n1 = 2 * t1.first * p1.first;
	d1 = t1.second * p1.second;
	n2 = t2.first;
	d2 = t2.second;
	n = (((n1 % 1000000007)*(d2 % 1000000007) % 1000000007) - ((n2 % 1000000007)*(d1 % 1000000007) % 1000000007)) % 1000000007;
	d = ((d1 % 1000000007) * (d2 % 1000000007)) % 1000000007;
	// cout << "t = " << t << "\n";
	// cout << "n1 = " << n1 << "\n";
	// cout << "d1 = " << d1 << "\n";
	// cout << "n2 = " << n2 << "\n";
	// cout << "d2 = " << d2 << "\n";
	// cout << "n = " << n << "\n";
	// cout << "d = " << d << "\n";
	hcf = gcd(n, d);
	n /= hcf;
	d /= hcf;
	dp[t].first = n;
	dp[t].second = d;
	// cout << "num = " << dp[t].first << "\n";
	// cout << "den = " << dp[t].second << "\n";
	v[t] = 1;
	return dp[t];
}

void te(){
	ll l, dn, t, tmp;
	read(l, dn, t);
	tmp = l;
	// ll hcf1 = __gcd(l, dn);
	// l /= hcf1;
	// dn /= hcf1;
	p0.first = 1;
	p0.second = 1;
	p1.first = dn;
	p1.second = l;
	p2.first = ((2 * ((dn % 1000000007) * (dn % 1000000007) % 1000000007)) % 1000000007 - (l * l) % 1000000007) % 1000000007;
	p2.second = ((l % 1000000007) * (l % 1000000007)) % 1000000007;
	memset(v, 0, sizeof(v));
	pair<ll, ll> ans = DP(t);
	n = ans.first;
	d = ans.second;
	hcf = __gcd(n, d);
	n /= hcf;
	d /= hcf;
	//cout << n << "/" << d << "\n";
	n = n * tmp;
	ll r = modInverse(d, 1000000007);
	ll fin = ((n % 1000000007) * (r % 1000000007)) % 1000000007; //((n% 1000000007) * (r% 1000000007)) % 1000000007;
	if(fin < 0)
		fin += 1000000007;
	cout << fin << "\n";
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