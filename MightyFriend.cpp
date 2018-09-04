#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <array>
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
	ll n, k; read(n, k);
	ll a[n]; for(ll i=0;i<n;i++) read(a[i]);

	ll b[(ll)ceil(n/2.0)], c[(ll)floor(n/2.0)];

	ll cb = 0, cc = 0;
	for(ll i=0;i<n;i++){
		if(i % 2 == 0)
			b[cb++] = a[i];
		else 
			c[cc++] = a[i];
	}

	sort(b, b + (ll) (ll)ceil(n/2.0));
	sort(c, c + (ll) (ll)floor(n/2.0));

	// cout << k << " - k\n";
	for(ll i=0;i<min(k, min((ll) (ll)ceil(n/2.0), (ll) (ll)floor(n/2.0)));i++){
		// cout << " -- " << c[i] << " " << b[(ll) (ll)ceil(n/2.0)-i-1] << "\n";
		if(c[i] < b[(ll) (ll)ceil(n/2.0)-1-i]){
			ll t = c[i];
			c[i] = b[(ll) (ll)ceil(n/2.0)-1-i];
			b[(ll) (ll)ceil(n/2.0)-1-i] = t;
		}
		else
			break;
	}

	ll sb = 0, sc = 0;

	for(ll i=0;i<(ll)ceil(n/2.0);i++){
		// cout << b[i] << " ";
		sb += b[i];
	}
	// cout << "\n";
	for(ll i=0;i<(ll)floor(n/2.0);i++){
		// cout << c[i] << " ";
		sc += c[i];
	}
	// cout << "\n";

	if(sc > sb) cout << "YES\n";
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

	ll T; read(T);
	while(T--) te();

	end_clock();							//This too.
	return 0;
}