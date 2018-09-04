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
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//start_clock();

	map<ll, ll> mp;
	ll s, flad = 0;
	read(s);
	ll a[s+1];
	for(ll i=0;i<s;i++){
		read(a[i]);
		mp[a[i]] = 1;
	}

	for(ll i=0;i<s;i++)
		for(ll j=i;j<s;j++)
			if(mp.find(a[i]+a[j]) != mp.end()){
				printf("%lld %lld %lld", a[i], a[j], a[i]+a[j]);
				flad = 1;
				goto afterLoop;
			}
	afterLoop:
	if(flad == 0)
		printf("%d", -1);

	//end_clock();
	return 0;
}