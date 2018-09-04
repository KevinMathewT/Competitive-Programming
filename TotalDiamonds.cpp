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

ll sum(ll n){
	ll even = 0, odd = 0, c = 1;
	while(n>0){
		if((n%10)%2 == 0)
			even += n % 10;
		else
			odd += n % 10;
		c++;
		n/=10;
	}
	return abs(odd-even);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	start_clock();

	ll t, dp[10000], cdpsum[20000+10];
	for(ll i=1;i<200+5;i++)
		cdpsum[i] = cdpsum[i-1]+sum(i);
	dp[1] = 2;
	for(ll i=2;i<100;i++)
		dp[i] = dp[i-1]+2*(cdpsum[2*i-1]-cdpsum[i])+sum(2*i);
	read(t);
	while(t--){
		ll n;
		read(n);
		printf("%lld\n", dp[n]);
	}

	end_clock();
	return 0;
}