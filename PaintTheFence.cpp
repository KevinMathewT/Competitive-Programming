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

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	start_clock();

	ll n, m;
	read(n, m);
	ll a[n], t=m;
	for(ll i=0;i<n;i++)
		a[i]=0;
	std::map<ll, pair<ll, ll> > map;
	while(m--){
		ll l, r;
		read(l, r);
		map[t-m-1]=make_pair(l-1, r-1);
		for(ll i=l-1;i<=r-1;i++)
			a[i]++;
	}
	ll noz=0;
	for(ll j=0;j<=n;j++)
			if(a[j]==0)
				noz++;
	for(ll i=0;i<t;i++){
		ll c=0;
		for(ll j=map[i].first;j<=map[i].second;j++)
			if(a[j]==1)
				c++;
		printf("%lld\n", c+noz);
	}

	end_clock();
	return 0;
}