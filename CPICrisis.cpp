#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef double ld;
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
	ll n, x; read(n, x);
	ll a[n+1]; for(ll i=1;i<=n;i++) read(a[i]);
	a[0] = 0;
	ld maxv = LLONG_MIN;
	ll cum[n+1];
	ll w[n+1];
	ll cumw[n+1];
	for(ll i=0;i<=n;i++){
		cumw[i] = i;
		w[i] = i;
	}
	for(ll i=1;i<=n;i++)
		cumw[i] += cumw[i-1];
	cum[0] = 0;
	w[0] = 0;
	for(ll i=1;i<=n;i++)
		cum[i] = cum[i-1]+a[i]*w[i];

	cout << fixed << setprecision(10);
	// for(ll i=0;i<=n;i++)
	// 	cout << a[i] << " ";
	// cout << "\n";
	// for(ll i=0;i<=n;i++)
	// 	cout << cum[i] << " ";
	// cout << "\n";
	// for(ll i=0;i<=n;i++)
	// 	cout << cumw[i] << " ";
	// cout << "\n";
	// for(ll i=0;i<=n;i++)
	// 	cout << w[i] << " ";
	// cout << "\n";

	for(ll i=1;i<=n;i++){
		for(ll j=i+x-1;j<=n;j++){
			ld v = ((cum[j])-(cum[i-1])+0.0) / (cumw[j]-cumw[i-1]+0.0);
			// cout << v << "\n";
			maxv = max(maxv, v);
		}
	}

	cout << maxv << "\n";
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