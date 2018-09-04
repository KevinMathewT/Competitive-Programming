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
	ll n, m, k;
	read(n, m, k);
	ll a[n], p[m], ans[n];
	for(ll i=0;i<n;i++) read(a[i]);
	for(ll i=0;i<m;i++) read(p[i]);

	for(ll i=0;i<n;i++){
		ll start = a[i];
		ll end = start + min(k, (ll)(1e8)/(n*m));
		ll mx = LLONG_MIN;
		ll v = start;
		for(ll j=start;j<=end;j++){
			ll curr = 1;
			for(ll l=0;l<m;l++){
				curr += (j % p[l]);
			}
			// cout << curr << "\n";
			if(curr > mx){
				mx = curr;
				v = j;
			}
		}
		// cout << "---------" << "\n";
		ans[i] = v;
	}

	for(ll i=0;i<n;i++)
		cout << ans[i] << " ";
	cout << "\n";
	ll prod = 1;
	for(ll i=0;i<n;i++)
		prod *= ans[i];

	ll b = 0;
	for(ll i=0;i<m;i++)
		b += prod % p[i];
	cout << b << "\n";
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