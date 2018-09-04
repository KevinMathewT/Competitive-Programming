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

void te(){
	double d_wall;
	cin >> d_wall;
	double d_fixed, l_fixed, len;
	cin >> d_fixed >> l_fixed >> len;
	double d_min;
	cin >> d_min;

	if(d_min + d_fixed >= d_wall){
		cout << "NO\n";
		return;
	}

	double minL = (l_fixed / 2.00) + (d_min + d_fixed) * ((l_fixed / 2.0) / d_fixed);
	double maxL = (l_fixed / 2.00) + (d_wall) * ((l_fixed / 2.0) / d_fixed);
	
	if(len < minL || len > maxL){
		cout << "NO\n";
		return;
	}
	maxL -= minL;
	double t = len;
	t -= minL;
	minL = 0;
	d_wall -= d_fixed + d_min;
	double ans = d_min + t * (maxL / d_wall);
	cout << "YES\n" << ans << "\n";
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
	while(t--) te();

	end_clock();							//This too.
	return 0;
}