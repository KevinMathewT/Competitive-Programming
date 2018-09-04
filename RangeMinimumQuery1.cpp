#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;
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
ll a[1000];
ll t[4*1000];

void create(ll i, ll l, ll r){
	if(l == r){
		t[i] = a[l];
		return;
	}
	create(2*i, l, (l + r)/2);
	create(2*i + 1, (l+r)/2 + 1, r);
	t[i] = min(t[2*i], t[2*i+1]);
}

void update(ll i, ll l, ll r, ll p, ll v){
	if(l==r){
		t[i] = v;
		a[p] = v;
		return;
	}
	ll mid = (l+r)/2;
	if(p <= mid)
		update(2*i, l, mid, p, v);
	else
		update(2*i+1, mid+1, r, p, v);
	t[i] = min(t[2*i], t[2*i+1]);
}

ll query(ll i, ll l, ll r, ll x, ll y){
	if(y < l || x > r)
		return LLONG_MAX-10;
	if(l >= x && r <= y)
		return t[i];
	ll mid = (l+r)/2;
	ll u = query(2*i, l, mid, x, y);
	ll v = query(2*i+1, mid+1, r, x, y);
	return min(u, v);
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll n, q;
	read(n, q);
	for(ll i=0;i<n;i++)
		read(a[i]);
	create(1, 0, n-1);

	while(q--){
		string ch;
		ll l, r;
		cin.ignore(256, '\n');
		cin >> ch;
		read(l, r);
		if(ch == "u")
			update(1, 0, n-1, l-1, r);
		else
			cout << query(1, 0, n-1, l-1, r-1) << "\n";
	}

	end_clock();							//This too.
	return 0;
}