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

ll dp[600][600];
ll a[600][600];
ll dpmin[600][600];

ll findmin(ll x, ll y, ll m){
	if(x == 1 && y == 1) return 1;
	ll ans = 0;
	if((a[x][y] + dp[x-1][y-1]) > m && (a[x][y] + dp[x][y-1]) > m && (a[x][y] + dp[x-1][y]) > m)
		return LLONG_MAX-10;
	if((a[x][y] + dp[x-1][y-1]) <= m)
		return 1 + findmin(x-1, y-1, m-a[x][y]);
	else
		return 1 + min(findmin(x-1, y, m-a[x][y]), findmin(x, y-1, m-a[x][y]));
}

void te(){
	ll n, m;
	read(n, m);
	ll x;
	read(x);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
			read(a[i][j]);

	for(ll i=0;i<=n;i++)
		dp[i][0] = LLONG_MAX-10;
	for(ll i=0;i<=m;i++)
		dp[0][i] = LLONG_MAX-10;
	dp[1][1] = a[1][1];
	
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++){
			if(i == 1 && j == 1) continue;
			dp[i][j] = a[i][j] + min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j]));
		}

	cout << x - dp[n][m] << " " << findmin(n, m, x) << "\n";
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