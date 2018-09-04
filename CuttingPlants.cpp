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

struct info{
	ll amax, amin, bmax, bmin;
};

ll a[1000];
ll b[1000];
info st[4*1000];
ll lazy[4*1000];
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
	ll n; read(n);
	for(ll i=0;i<4*n;i++) lazy[i] = -1;
	for(ll i=0;i<n;i++) read(a[i]);
	for(ll i=0;i<n;i++) read(b[i]);
	create(1, 0, n-1);

	map<ll, vector<ll> > m;
	map<ll, ll> pos;

	for(ll i=0;i<n;i++){
		if(b[i] != a[i])
			m[b[i]].push_back(i);
		pos[b[i]] = 0;
	}

	for(ll i=0;i<n;i++)
		if(b[i] > a[i]){
			cout << "-1\n";
			return;
		}

	// cout << query(1, 0, n-1, 0, n-1).amax << "\n";
	// for(ll i=0;i<n;i++)
	// 	cout << query(1, i, i, 0, n-1).amax << " ";
	// cout << "\n";
	// update(1, 3, 5, 0, n-1, 0);
	// for(ll i=0;i<n;i++)
	// 	cout << query(1, i, i, 0, n-1).amax << " ";
	// cout << "\n";
	// cout << query(1, 0, n-1, 0, n-1).amax << "\n";

	// cout << pos[1] << " " << pos[2] << "\n";
	// for(ll i=0;i<m[2].size();i++)
	// 	cout << m[2][i] << " ";
	// cout << "\n";
	ll answer = 0;

	for(ll i=0;i<n;i++){
		if(b[i] == query(1, i, i, 0, n-1).amax) continue;
		ll l = pos[b[i]];
		ll r = m[b[i]].size() - 1;
		ll p = -1;
		// cout << l << " " << r << "\n";
		for(ll j=l+1;j<=r;j++){
			// cout << m[b[i]][l] << " - " << m[b[i]][j] << " ";
			info about = query(1, m[b[i]][l], m[b[i]][j], 0, n-1);
			// cout << about.amin << " -- " << about.bmax << " ";
			ll cond = (about.amin >= b[i]) && (about.bmax <= b[i]);
			// cout << cond << "\n";
			if(cond){  p = j; }
			else { break; }
		}
		// while(l < r){
		// 	ll mid = (l + r) / 2;
		// 	info about = query(1, m[b[i]][l], m[b[i]][mid], 0, n-1);
		// 	ll cond = (about.amin > b[i]) && (about.bmax <= b[i]);
		// 	if(cond) l = mid + 1;
		// 	else r = mid;
		// }
		if(p == -1)
			p = l;
		update(1, m[b[i]][l], m[b[i]][p], 0, n-1, b[i]);
		pos[b[i]] = min(p+1, (ll)(m[b[i]].size()-1));
		answer++;
		// for(ll i=0;i<n;i++)
		// 	cout << query(1, i, i, 0, n-1).amax << " ";
		// cout << "\n";
	}

	// for(ll i=0;i<n;i++)
	// 	cout << query(1, i, i, 0, n-1).amax << " ";
	// cout << "\n";

	cout << answer << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	failcase.amax = LLONG_MIN;
	failcase.amin = LLONG_MAX;
	failcase.bmax = LLONG_MIN;
	failcase.bmin = LLONG_MAX;
	ll T; read(T);
	while(T--) te();

	end_clock();							//This too.
	return 0;
}