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
	ll n, r; read(n, r);
	ll a[n]; for(ll i=0;i<n;i++) read(a[i]);
	// if(n == 1){ cout << "YES\n"; return;}

	ll h = LLONG_MAX, l = LLONG_MIN, flag = 1;
	for(ll i=0;i<n;i++){
		if(a[i] > r && a[i] > h){
			flag = 0; break;
		}
		if(a[i] < r && a[i] < l){
			flag = 0; break;
		}
		if(a[i] > r && a[i] < h){
			h = a[i];
		}
		if(a[i] < r && a[i] > l){
			l = a[i];
		}
	}
	if(flag == 1) cout << "YES\n";
	else cout << "NO\n";
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