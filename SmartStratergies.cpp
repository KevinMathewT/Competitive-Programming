#include <bits/stdc++.h>
#include <iostream>
#include <vector>
typedef unsigned long long ll;
typedef long double ld;
typedef std::vector<ll> vl;
typedef std::vector<vl> vvl;
void read(ll &x){
	scanf("%lld",&x);
}
void read(ll &x,ll &y){
	scanf("%lld%lld",&x,&y);
}
void read(ll &x,ll &y,ll &z){
	scanf("%lld%lld%lld",&x,&y,&z);
}
void read(ll &x,ll &y,ll &z,ll &w){
	scanf("%lld%lld%lld%lld",&x,&y,&z,&w);
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

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//start_clock();
	ll t;
	read(t);
	while(t--){
		ll n, q;
		read(n, q);
		ll d[n+1];
		for(ll i=0;i<n;i++)
			read(d[i]);
		ll x[q+1];
		for (ll i = 0; i < q; i++)
			read(x[i]);
		ll prod = 1;
		for (ll i = 0; i < n; ++i)
			prod *= d[i];

		for(ll i=0;i<q;i++)
			printf("%lld ", (x[i]/prod));
		printf("\n");
	}
	//end_clock();
	return 0;
}