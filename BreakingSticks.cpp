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


std::map<ll, ll> mp;

ll calc(ll n){
	if(mp.find(n)!=mp.end())
		return mp[n];
	ll mini = LLONG_MIN;
	for(ll i=2;i<=sqrt(n);i++){
		if(n%i == 0){
			ll val1 = 1 + i*calc(n/i);
			ll val2 = 1 + (n/i)*calc(i);
			mini = max(mini, max(val1, val2));
		}
	}
	return mp[n]=max(mini, n+1);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	start_clock();

	mp[1]=1L;
	mp[2]=3L;
	mp[3]=4L;
	ll t, sum = 0;
	read(t);
	while(t--){
		ll n;
		read(n);
		sum+=calc(n);
	}
	printf("%lld\n", sum);
	end_clock();
	return 0;
}