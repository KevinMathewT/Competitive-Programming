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

ll getEvens(ll x, ll y){
	if(x % 2 != 0) x++;
	if(y % 2 != 0) y--;
	return ((y - x)/2 + 1) > 0 ? ((y - x)/2 + 1) : 0;
}

ll getOdds(ll x, ll y){
	if(x % 2 == 0) x++;
	if(y % 2 == 0) y--;
	return ((y - x)/2 + 1) > 0 ? ((y - x)/2 + 1) : 0;
}

void te(){
	ll n, minx, maxx;
	read(n, minx, maxx);
	ll w[n], b[n];
	for(ll i=0;i<n;i++)
		read(w[i], b[i]);

	ll v1 = w[0] + b[0];
	for(ll i=1;i<n;i++)
		v1 = w[i] * v1 + b[i];

	ll v2 = w[0]*2 + b[0];
	for(ll i=1;i<n;i++)
		v2 = w[i] * v2 + b[i];

	if(v1 % 2 == 0 && v2 % 2 == 0)
		cout << (maxx - minx + 1) << " 0" << "\n";

	if(v1 % 2 != 0 && v2 % 2 != 0)
		cout << "0 " << (maxx - minx + 1) << "\n";

	if(v1 % 2 == 0 && v2 % 2 != 0)
		cout << getOdds(minx, maxx) << " " << getEvens(minx, maxx) << "\n";

	if(v1 % 2 != 0 && v2 % 2 == 0)
		cout << getEvens(minx, maxx) << " " << getOdds(minx, maxx) << "\n";

}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this
	// start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	read(T);
	while(T--) te();

	// end_clock();							//This too.
	return 0;
}