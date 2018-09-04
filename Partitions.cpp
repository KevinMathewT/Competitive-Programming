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

ll a[1000100];
ll cum[1000100];
ll n;
ll bs(ll l, ll val){
	// cout << "--- " << val << "\n";
	ll c = 0;
	while(l < n){
		// cout << l << "\n";
		ll v = lower_bound(cum + l, cum + n, val + cum[l-1]) - cum;
		// cout << "-- " << v << " " << l-1 << "\n";
		if(cum[v] - cum[l-1] != val) return -1;
		c++;
		l = v + 1;
	}
	// cout << "---\n";
	return c;
}

void te(){
	// cout << "-------------------\n";
	for(ll f=0;f<=1000000000;f++){
	n = 1;
	// for(ll i=0;i<n;i++) read(a[i]);
	a[0] = f;
	ll ans[n];
	for(ll i=0;i<n;i++) ans[i] = 0;
	cum[0] = a[0];
	for(ll i=1;i<n;i++) cum[i] = a[i] + cum[i-1];
	for(ll i=1
0;i<n;i++){
		ll z = bs(i+1, cum[i]);
		if(z == -1) continue;
		else ans[z] = 1;
	}

	for(ll i=0;i<n;i++) cout << ans[i];
	cout << "\n";
	}
	// cout << "-------------------\n";
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