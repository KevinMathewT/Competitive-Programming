#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define INF LLONG_MAX
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

ll st[4000+1];
ll build(ll a[], ll p, ll l, ll r){
	if(l == r)
		return st[p] = a[l];
	return st[p] = min(build(a, p<<1, l, (l+r)/2), build(a, (p<<1) + 1, ((l+r)/2) + 1, r));
}

ll rmq(ll *a, ll p, ll x, ll y, ll l, ll r){
	if(x<=l && y>=r) return st[p];
	if(x>r || y<l) return INF;
	return min(rmq(a, 2*p, x, y, l, (l+r)/2), rmq(a, (2*p) + 1, x, y, ((l+r)/2)+1, r));
}

void update(ll *a, ll p, ll i, ll l, ll r){
	if(l == r && l == i){
		st[p] = a[i];
		return;
	}
	if(a[i]<st[p])
		st[p]=a[i];
	if(i<=(l+r)/2)
		update(a, p<<1, i, l, (l+r)/2);
	else
		update(a, (p<<1) + 1, i, ((l+r)/2)+1, r);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	start_clock();

	ll n, m;
	read(n, m);
	ll a[n];
	for(ll i=0;i<n;i++)
		read(a[i]);
	build(a, 1, 0, n-1);
	while(m--){
		char q, z;
		scanf("%c", &z);
		ll lx, ry;
		scanf("%c", &q);
		read(lx, ry);
		if(q == 'q')
			printf("%lld\n", rmq(a, 1, lx, ry, 0, n-1));
		if(q == 'u'){
			a[lx] = ry;
			update(a, 1, lx, 0, n-1);
		}
	}

	end_clock();
	return 0;
}