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

ll a[100000+5];
ll st[400000+5];

ll createSegmentTree(ll a[], ll p, ll l, ll r){
	if(l == r){
		st[p]=a[l];
		return st[p];
	}
	
	ll mid = (l+r)/2;
	ll half = a[l]+a[r]/2;
	ll lv = createSegmentTree(a, 2*p, l, mid);
	ll rv = createSegmentTree(a, (2*p)+1, mid+1, r);
	return st[p] = abs((float)lv-(float)half)<abs((float)rv-(float)half) ? lv : rv;
}

ll query(ll p, ll x, ll y, ll l , llr){
	if(x == l && y == r)
		return st[p];
	ll mid = (l+r)/2;
	if(l<mid && r<mid)
		return query()
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	start_clock();

		ll t;
		read(t);
		while(t--){
			ll n, q;
			ll a[n+1];
			for(ll i=0;i<n;i++)
				read(a[i]);
			createSegmentTree(a, 1, 0, n-1);

		}


	end_clock();
	return 0;
}