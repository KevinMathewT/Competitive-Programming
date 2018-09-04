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

	ll n, a, b;
	read(n, a, b);
	read(a);
	read(b);
	for(ll i=0;i<(n/a);i++){
		long double y = (double)(n-i*a)/(double)b;
		if(y == round(y)){
			printf("YES\n%lld %lld", i, (ll)y);
			return 0;
		}
	}
	printf("NO\n");

	end_clock();
	return 0;
}