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

ll n;
ll a[1000];
ll st[4*1000];
ll lazy[4*1000];

void doLazy(ll i, ll s, ll e, ll l, ll r, ll val){
	if(lazy[i] != 0){
		st[i] += lazy[i];
		if(s != e){
			lazy[2*i] += lazy[i];
			lazy[(2*i)+1] += lazy[i];
		}
		lazy[i] = 0;
	}
	if(r < s || l > e || s > e)
		return;
	if(l <= s && r >= e){
		st[i] += val;
		if(l != r){
			lazy[2*i] += val;
			lazy[(2*i)+1] += val;
		}
		return;
	}
	ll mid = (s+e)/2;
	doLazy(2*i, s, mid, l, r, val);
	doLazy((2*i)+1, mid+1, e, l, r, val);
	st[i] = max(st[2*i], st[(2*i)+1]);
}

ll query(ll i, ll s, ll e, ll l, ll r){
	if(s>r || e<l || s>e) return LLONG_MIN+10;
	if(lazy[i] != 0){
		st[i] += lazy[i];
		if(s != e){
			lazy[2*i] += lazy[i];
			lazy[(2*i)+1] += lazy[i];
		}
		lazy[i] = 0;
	}
	if(l<=s && r>=e) return st[i];
	ll mid = (s+e)/2;
	ll x = query(2*i, s, mid, l, r);
	ll y = query((2*i)+1, mid+1, e, l, r);
	return max(x, y);
}

ll createSegTree(ll i, ll l, ll r){
	if(l == r){
		st[i] = a[l];
		return st[i];
	}
	ll x = createSegTree(2*i, l, (l+r)/2);
	ll y = createSegTree(2*i + 1, (l+r)/2 + 1, r);
	st[i] = max(x, y);
	return st[i];
}

void te(){
	read(n);
	for(ll i=0;i<n;i++)
		read(a[i]);
	createSegTree(1, 0, n-1);
	// for(ll i=0;i<400;i++)
	// 	cout << i << " " << st[i] << " " << lazy[i] << "\n";

	ll q;
	read(q);
	while(q--){
		ll type;
		read(type);
		// cout << type << "----\n";
		if(type == 1){
			ll l, r, val;
			// cout << "Reached Here 1\n";
			read(l, r, val);
			// cout << l << " " << r << " " << val << "\n";
			doLazy(1, 0, n-1, l-1, r-1, val);
			// cout << "---------------------";
			// for(ll i=0;i<40;i++)
			// 	cout << i << " " << st[i] << " " << lazy[i] << "\n";
			// cout << "---------------------";
			// cout << "Reached Here 2\n";
		}
		if(type == 2){
			// cout << "Reached Here 3\n";
			ll pos;
			read(pos);
			// cout << pos << "\n";
			ll x = query(1, 0, n-1, pos-1, n-1);
			// if(x == query(1, 0, n-1, pos-1, pos-1)){
			// 	cout << "WOW\n";
			// }
			// else
				cout << x << "\n";
			// cout << "Reached Here 4\n";
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