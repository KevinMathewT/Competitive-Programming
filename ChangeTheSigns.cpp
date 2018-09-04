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

ll a[1001000];
ll st[4*1001000];
ll n;

void update(ll i, ll p, ll v, ll l, ll r){
	if(p < l || p > r)
		return;
	if(l == r){
		st[i] = v;
		a[i] = v;
		return;
	}

	ll mid = (l + r) / 2;
	update(2*i, p, v, l, mid);
	update(2*i+1, p, v, mid+1, r);

	st[i] = st[2*i] + st[2*i+1];
}

ll query(ll i, ll x, ll y, ll l, ll r){
	if(r < x || l > y)
		return 0;

	if(l >= x && r <= y)
		return st[i];

	ll mid = (l + r) / 2;
	return query(2*i, x, y, l, mid) + query(2*i+1, x, y, mid+1, r);
}

void createSegTree(ll i, ll l, ll r){
	if(l == r){
		st[i] = a[l];
		return;
	}
	ll mid = (l + r) / 2;
	
	createSegTree(2*i, l, mid);
	createSegTree(2*i+1, mid+1, r);

	st[i] = st[2*i] + st[2*i+1];
}

void te(){
	read(n);
	for(ll i=0;i<n;i++)
		read(a[i]);

	if(n == 2 && a[0] == a[1]){
		cout << a[0] << " " << a[1] << "\n";
		return;
	}
	
	createSegTree(1, 0, n-1);

	// for(ll i=0;i<4*n;i++)
	// 	cout << st[i] << "\n";

	vector<ll> v;

	if(a[0] < a[1]) v.push_back(0);
	for(ll i=1;i<n-1;i++){
		if(a[i] < a[i-1] && a[i] < a[i+1])
			v.push_back(i);
	}
	if(a[n-1] < a[n-2]) v.push_back(n-1);

	for(ll i=0;i<v.size();i++)
		cout << v[i] << " ";
	cout << "----\n";

	// for(ll i=0;i<v.size()-1;i++){
	// 	// cout << v[i]+1 << " " << v[i+1]-1 << "-\n";
	// 	ll s = query(1, v[i]+1, v[i+1]-1, 0, n-1);
	// 	// cout << s << "--\n";
	// 	if(s > (a[v[i]]+a[v[i+1]]))
	// 		update(1, v[i], -a[v[i]], 0, n-1);
	// }

	// if(v.size() >= 2)
	// 	update(1, v[v.size()-1], -a[v[v.size()-1]], 0, n-1);

	// for(ll i=0;i<n;i++)
	// 	cout << query(1, i, i, 0, n-1) << " ";
	// cout << "\n";
	// cout << "--------------\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T; read(T);
	while(T--) te();

	end_clock();							//This too.
	return 0;
}