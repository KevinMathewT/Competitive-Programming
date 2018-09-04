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

ll a[100010];
ll dp[100010][110];
ll n;

ll DP(ll pos, ll val){
	if(pos >= n) return 0;
	if(pos == n-1)
		max(abs(val-1), abs(a[pos]-val));
	if(dp[pos][val] != -1) return dp[pos][val];
	ll ans = max(abs(a[pos]-val)+DP(pos+1, a[pos]), abs(1-val)+DP(pos+1, 1));

	return dp[pos][val] = ans;
}

void te(){
	for(ll i=0;i<100010;i++)
		for(ll j=0;j<110;j++)
			dp[i][j] = -1;
	read(n);
	for(ll i=0;i<n;i++) read(a[i]);

	ll ans = LLONG_MIN;
	for(ll i=1;i<=a[0];i++)
		ans = max(ans, DP(1, i));

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