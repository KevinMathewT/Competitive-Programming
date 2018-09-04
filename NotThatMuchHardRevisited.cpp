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

ll a[100100];
ll n, m;



void te(){
	// Square Root Decomposition
	read(n, m);
	for(ll i=0;i<n;i++) read(a[i]);
	ll ans[300+5];
	for(ll i=0;i<=300;i++)
		ans[i] = 1;

	for(ll i=0;i<n;i++){
		ans[i/300] = (((ans[i/300]+m)%m) * ((((1 + a[i])+m)%m))+m)%m;
		// cout << ans[i/300] << " " << (i/300) << "\n"; 
	}

	ll q; read(q);
	while(q--){
		ll x, y;
		read(x, y); x--; y--;

		ll f = (1+a[x]) % m, s = 1, t = (1+a[y]) % m;
		for(ll i=x+1;i<=y && (i % 300) != 0;i++)
			f = (((f+m)%m) * ((((1+a[i])+m)%m)) +m)%m;
		for(ll i=y-1;i>=x && ((i+1) % 300) != 0;i--)
			t = (((t+m)%m) * ((((1+a[i])+m)%m)) +m)%m;
		for(ll i=(x/300)+1; i<(y/(300));i++)
			s = (((s+m)%m) * ((((ans[i])+m)%m)) +m)%m;

		if(x/300 == y/300)
			cout << ((f+m)%m) << "\n";
		else
			cout << (((((f+m)%m) * ((s+m)%m) * ((t+m)%m)) +m)%m) << "\n";
		// cout << f << " " << s << " " << t << "\n";
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