#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <utility>
typedef long long ll;
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

ll recurse(ll *a, ll p, ll n){
	if(p >= n) return 0;
	for(ll i=p;i<n-1;i++){
		if(a[i+1]<=a[i]){
			ll t = a[i+1];
			a[i+1]=a[i]+1;
			ll val1 = recurse(a, p+1, n);
			a[i+1]=t;
			a[i]--;
			ll val2 = recurse(a, 0, n);
			return min(1+val1, val2);
		}
	}
	return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	start_clock();

	ll n;
	read(n);
	ll a[n], b[n];

	for(ll i=0;i<n;i++){
		read(a[i]);
		b[i]=a[i];
	}

	printf("%lld\n", recurse(a, 0, n));

	end_clock();
	return 0;
}