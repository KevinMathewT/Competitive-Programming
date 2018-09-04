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

map<ll, map<ll, ll> > dp;
ll n, k, x;

ll DP(ll pos, ll val){
	if(pos == n-1){
		if(val == x) return 0;
		return 1;
	}
	if(dp[pos][val] != 0) return dp[pos][val];

	ll ans = 0;
	for(ll i=1;i<k;i++)
		if(i != val)
			ans += DP(pos+1, i);
	return dp[pos][val] = 1 + ans;
}

void te(){
	read(n, k, x);
	// cout << DP(1, 1) << "\n";

	if(n == 3){
		if(x == 1) cout << k-1 << "\n";
		else cout << k-2 << "\n";
	}
	if(n == 4){
		
	}
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