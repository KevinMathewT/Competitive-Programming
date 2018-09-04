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

ll n, m;
ll c[100];
ll DP[500][500];

ll dp(ll n, ll co){
	if(n < 0) return 0;
	if(n == 0) return 1;
	if(DP[n][co] != -1) return DP[n][co];

	ll sum = 0;
	for(ll i=m-1;i>=0;i--){
		if(c[i] <= co) sum += dp(n - c[i], c[i]);
	}

	return DP[n][co] = sum;
}

void te(){
	read(n, m);
	for(ll i=0;i<500;i++)for(ll j=0;j<500;j++) DP[i][j] = -1;
	DP[0][0] = 1;
	for(ll i=0;i<m;i++) read(c[i]);
	sort(c, c+m);
	cout << dp(n, LLONG_MAX) << "\n";
	// cout << "\n";
	// for(ll i=0;i<=n;i++) cout << DP[i] << " ";
	// cout << "\n"; 
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output1.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	end_clock();							//This too.
	return 0;
}