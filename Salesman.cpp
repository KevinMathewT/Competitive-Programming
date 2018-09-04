#include <bits/stdc++.h>
#include <iostream>
#include <vector>
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

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	start_clock();

	ll t;
	read(t);
	while(t--){
		ll n;
		read(n);
		ll a[n], max = LLONG_MIN, min = LLONG_MAX;
		for(ll i=0;i<n;i++){
			read(a[i]);
			max = a[i] > max ? a[i]:max;
			min = a[i] < min ? a[i]:min;
		}
		for(ll i=0;i<n;i++)
			printf("%lld\n", a[i]);
		printf("%lld %lld %lld\n", max, min, abs(max-min));
	}

	end_clock();
	return 0;
}