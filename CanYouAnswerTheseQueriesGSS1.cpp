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

struct Sums
{
	ll prefix;
	ll suffix;
	ll maxsum;
	ll sum;
};

Sums st[200000];

void build(ll *a, ll p, ll l, ll r){
	if(l == r){
		st[p].prefix = a[l];
		st[p].suffix = a[l];
		st[p].maxsum = a[l];
		st[p].sum = a[l];
		return;
	}
	build(a, p<<1, l, (l+r)>>1);
	build(a, (p<<1)+1, ((l+r)>>1)+1, r);
	st[p].sum = st[p<<1].sum + st[(p<<1)+1].sum;
	st[p].maxsum = max(st[p<<1].suffix+st[(p<<1)+1].prefix, max(st[p<<1].maxsum, st[(p<<1)+1].maxsum));
	st[p].prefix = max(st[p<<1].prefix, st[p<<1].sum+st[(p<<1)+1].prefix);
	st[p].suffix = max(st[(p<<1)+1].suffix, st[(p<<1)+1].sum+st[p<<1].suffix);
}

Sums query(ll *a, ll p, ll l, ll r, ll x, ll y){
	//printf("Reached here for %lld %lld and %lld %lld for %lld\n", l, r, x, y, p);
	if(x==l && y==r) return st[p];
	ll mid = (l+r)>>1;
	if(x>mid) return query(a, (p<<1)+1, mid+1, r, x, y);
	if(y<=mid) return query(a, p<<1, l, mid, x, y);
	Sums left = query(a, p<<1, l, mid, x, mid);
	Sums right = query(a, (p<<1)+1, mid+1, r, mid+1, y);
	Sums tbReturned;
	tbReturned.sum = left.sum + right.sum;
	tbReturned.maxsum = max(left.suffix+right.prefix, max(left.maxsum, right.maxsum));
	tbReturned.prefix = max(left.prefix, left.sum+right.prefix);
	tbReturned.suffix = max(right.suffix, right.sum+left.suffix);
	return tbReturned;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	start_clock();

	ll n;
	read(n);
	
	ll a[n];
	for(ll i=0;i<n;i++)
		read(a[i]);

	build(a, 1, 0, n-1);

	//for(ll i=0;i<4*n;i++)
	//	printf("%lld %lld %lld %lld\n", st[i].sum, st[i].maxsum, st[i].prefix, st[i].suffix);

	ll m;
	read(m);

	while(m--){
		ll x, y;
		read(x, y);
		printf("%lld\n", query(a, 1, 0, n-1, x-1, y-1).maxsum);
	}

	end_clock();
	return 0;
}