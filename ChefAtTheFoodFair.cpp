#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define F0(i,n) for (ll i = 0; i < n; i++)
#define F1(i,n) for (ll i = 1; i <= n; i++)
#define CL(a,x) memset(x, a, sizeof(x));
#define SZ(x) ((int)x.size())

void read(ll &x){
	cin >> x;
}
void read(ll &x,ll &y){
	cin >> x >> y;
}
void read(ll &x,ll &y,ll &z){
	cin >> x >> y >> z;
}
void read(ll &x,ll &y,ll &z,ll &w){
	cin >> x >> y >> z >> w;
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

bool IsOdd(ll n){ return n % 2 == 1; }

ld a[1000];
ld st[4*1000];
ld lazy[4*1000];
info failcase;

void update(ll i, ll x, ll y, ll l, ll r, ll v){
	if(lazy[i] != -1){
		st[i].amax = lazy[i];
		st[i].amin = lazy[i];
		if(l != r){
			lazy[2*i] = lazy[i];
			lazy[2*i+1] = lazy[i];
		}
		lazy[i] = -1;
	}

	if(r < x || l > y) return;
	if(l >= x && r <= y){
		st[i].amax = v;
		st[i].amin = v;
		if(l != r){
			lazy[2*i] = v;
			lazy[2*i+1] = v;
		}
		return;
	}

	ll mid = (l + r) / 2;
	update(2*i, x, y, l, mid, v);
	update(2*i+1, x, y, mid+1, r, v);

	info left = st[2*i];
	info right = st[2*i+1];

	st[i].amax = max(left.amax, right.amax);
	st[i].amin = min(left.amin, right.amin);
}

info query(ll i, ll x, ll y, ll l, ll r){
	if(lazy[i] != -1){
		st[i].amax = lazy[i];
		st[i].amin = lazy[i];
		if(l != r){
			lazy[2*i] = lazy[i];
			lazy[2*i+1] = lazy[i];
		}
		lazy[i] = -1;
	}

	if(r < x || l > y) return failcase;
	if(l >= x && r <= y) return st[i];

	ll mid = (l+r) / 2;
	info left = query(2*i, x, y, l, mid);
	info right = query(2*i+1, x, y, mid+1, r);
	info ans;

	ans.amax = max(left.amax, right.amax);
	ans.amin = min(left.amin, right.amin);
	ans.bmax = max(left.bmax, right.bmax);
	ans.bmin = max(left.bmin, right.bmin);

	return ans;
}

void create(ll i, ll l, ll r){
	if(l == r){
		st[i].amax = a[l];
		st[i].amin = a[l];
		st[i].bmax = b[l];
		st[i].bmin = b[l];
		return;
	}

	ll mid = (l+r) / 2;
	create(2*i, l, mid);
	create(2*i+1, mid+1, r);

	info left = st[2*i];
	info right = st[2*i+1];

	st[i].amax = max(left.amax, right.amax);
	st[i].amin = min(left.amin, right.amin);
	st[i].bmax = max(left.bmax, right.bmax);
	st[i].bmin = max(left.bmin, right.bmin);
}

void te(){
	ll n, q;
	read(n, q);
	ld p[n]; for(ll i=0;i<n;i++) cin >> p[i];

	cout << fixed << setprecision(10);
	while(q--){
		ll q; read(q);
		if(q == 0){
			ll l, r; read(l, r);
			ld ans = 1.0;
			for(ll i=l-1;i<=r-1;i++)
				ans *= (1-p[i]);
			cout << ans << "\n";
		}
		else{
			ll l, r; ld t; read(l, r); cin >> t;
			for(ll i=l-1;i<=r-1;i++)
				p[i] *= t;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	end_clock();							//This too.
	return 0;
}