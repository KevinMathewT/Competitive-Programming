#include <bits/stdc++.h>
#include <iostream>
#include <string>
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
	//start_clock();

	ll n;
	read(n);
	ll a[n];
	for(ll i=0;i<n;i++)
		read(a[i]);
	ll sum1=0, sum2=0;
	for(ll i=0;i<(n/2);i++)
		sum1+=a[i];
	for(ll i=(n/2);i<n;i++)
		sum2+=a[i];
	printf("%lld", abs(sum1-sum2));

	//end_clock();
	return 0;
}