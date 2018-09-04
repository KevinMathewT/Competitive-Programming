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

ll st[400+10][2];

ll* build(ll *a, ll p, ll l, ll r){
	printf("Reached here for %lld between %lld and %lld\n", p, l, r);
	if(l == r){
		st[p][0] = a[l];
		st[p][1] = 1;
		return st[p];
	}
	ll* lz = build(a, p<<1, l, (l+r)/2);
	ll* rz = build(a, (p<<1)+1, ((l+r)/2) + 1, r);
	ll lv[2], rv[2], ans[2];
	lv[0]=lz[0];
	lv[1]=lz[1];
	rv[0]=rz[0];
	rv[1]=rz[1];
	if(lv[0]==rv[0]){
		printf("Entered here 1\n");
		ans[0]=lv[0];
		ans[1]=lv[1]+rv[1];
	}
	else if(lv[1]>rv[1]){
		printf("Entered here 2\n");
		ans[0]=lv[0];
		ans[1]=lv[1];
	}
	else{
		printf("Entered here 3\n");
		ans[0]=rv[0];
		ans[1]=rv[1];
	}
	st[p][0]=ans[0];
	st[p][1]=ans[1];
	return st[p];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	start_clock();

	ll t=1;
	printf("Hey!\n");
	while(t--){
		ll n, q;
		read(n, q);
		ll a[n];
		for(ll i=0;i<n;i++)
			read(a[i]);
		for(ll i=0;i<n;i++)
			printf("%lld ", a[i]);
		build(a, 1, 0, n-1);
		for(ll i=0;i<4*n;i++)
			printf("%lld %lld\n", st[i][0], st[i][1]);
		while(q--){
			ll l, r;
			read(l, r);
		}
	}

	end_clock();
	return 0;
}