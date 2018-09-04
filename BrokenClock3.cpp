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
#define MOD % 1000000007

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



void te(){
	ll l, dn, t;
	read(l, dn, t);
	ll temp = l;
	pair<ll, ll> dp[t];
	// ll hcf = __gcd(l, dn);
	// l /= hcf;
	// dn /= hcf;
	//Intialization
	dp[1].first = dn;
	dp[1].second = l;
	dp[2].first = (2 * (dn MOD) * (dn MOD)) MOD - ((l MOD) * (l MOD)) MOD;
	// dp[2].second = l * l;
	dp[2].second = ((l MOD) * (l MOD)) MOD;
	//Initialization done

	if(t > 2){
		for(ll i=3;i<=t;i++){
			ll a = dp[i-1].first;
			ll b = dp[i-1].second;
			ll c = dp[1].first;
			ll d = dp[1].second;
			ll e = dp[i-2].first;
			ll f = dp[i-2].second;
			dp[i].first = ((2*(a MOD)*(c MOD)*(f MOD)) MOD - ((b MOD)*(d MOD)*(e MOD))) MOD;
			dp[i].second = ((b MOD)*(d MOD)*(f MOD)) MOD;
		}
	}

	//F0(i, t) cout << dp[i].first << "/" << dp[i].second << "\n";

	//cout << dp[t].first << "/" << dp[t].second << "\n";
	dp[t].first = ((dp[t].first MOD) * (temp MOD)) MOD;
	ll hcf = __gcd(dp[t].first, dp[t].second);
	dp[t].first /= hcf;
	dp[t].second /= hcf;
	//cout << dp[t].first << "/" << dp[t].second << "\n";
	ll r = modInverse(dp[t].second, 1000000007);
	// cout << " r - "<< r << "\n";
	ll ans = ((dp[t].first MOD) * (r MOD)) MOD;
	if(ans < 0)
		ans += 1000000007;
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

	ll T;
	read(T);
	while(T--) te();

	end_clock();							//This too.
	return 0;
}