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


ll a[100][100];
ll dp[100][100];
ll s;

ll DP(ll x, ll y){
	if(x == s-1)
		return a[x][y];
	if(dp[x][y] != -1) return dp[x][y];
	else return dp[x][y] = (a[x][y] + max(DP(x+1, y), DP(x+1, y+1)));
}



bool IsOdd(ll n){ return n % 2 == 1; }

void te(){
	read(s);
	for(ll i=0;i<100;i++)
		for(ll j=0;j<100;j++)
			dp[i][j] = -1;
	for(ll i=0;i<s;i++)
		for(ll j=0;j<=i;j++)
			read(a[i][j]);
	// for(ll i=0;i<s;i++){
	// 	for(ll j=0;j<=;j++)
	// 		cout << a[i][j] << " ";
	// 	cout << "\n";
	// }

	cout << DP(0, 0) << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll n;
	read(n);
	while(n--) te();

	end_clock();							//This too.
	return 0;
}