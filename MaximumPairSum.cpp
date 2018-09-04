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

struct paired{
	ll a, b;
};

ll a[200000];
paired t[4*200000];
paired nul;

void create(ll i, ll l, ll r){
	if(l+1 == r){
		t[i].a = max(a[l], a[r]);
		t[i].b = min(a[l], a[r]);
		t[2*i].a = a[l];
		t[2*i].b = LLONG_MIN+10;
		t[2*i+1].a = a[r];
		t[2*i+1].b = LLONG_MIN+10;
		return;
	}
	if(l == r){
		t[i].a = a[l];
		t[i].b = LLONG_MIN+10;
		return;
	}
	ll mid = (l+r)/2;
	create(2*i, l, mid);
	create(2*i+1, mid+1, r);
	paired f = t[2*i];
	paired s = t[2*i+1];
	if(f.a > s.a){
		t[i].a = f.a;
		t[i].b = max(f.b, s.a);
	}
	else{
		t[i].a = s.a;
		t[i].b = max(s.b, f.a);
	}
}

void update(ll i, ll l, ll r, ll p, ll v){
	if(l == r){
		t[i].a = v;
		return;
	}
	// if(l+1 == r){
	// 	if(v > t[i].a){
	// 		t[i].b = t[i].a;
	// 		t[i].a = v;
	// 	}
	// 	else if(v > t[i].b){
	// 		t[i].b = v;
	// 	}
	// 	else{
	// 	}
	// 	if(p == l)
	// 		update(2*i, l, l, p, v);
	// 	else
	// 		update(2*i+1, r, r, p, v);
	// 	return;
	// }
	ll mid = (l+r)/2;
	if(p <= mid)
		update(2*i, l, mid, p, v);
	else
		update(2*i+1, mid+1, r, p, v);
	paired f = t[2*i];
	paired s = t[2*i+1];
	if(f.a > s.a){
		t[i].a = f.a;
		t[i].b = max(f.b, s.a);
	}
	else{
		t[i].a = s.a;
		t[i].b = max(s.b, f.a);
	}
}

paired query(ll i, ll l, ll r, ll x, ll y){
	if(l > y || r < x)
		return nul;
	if(l >= x && r <= y)
		return t[i];
	ll mid = (l+r)/2;
	paired f = query(2*i, l, mid, x, y);
	paired s = query(2*i+1, mid+1, r, x, y);
	paired ans;
	if(f.a > s.a){
		ans.a = f.a;
		ans.b = max(f.b, s.a);
	}
	else{
		ans.a = s.a;
		ans.b = max(s.b, f.a);
	}
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	nul.a = LLONG_MIN + 10;
	nul.b = LLONG_MIN + 10;
	ll n;
	read(n);
	for(ll i=0;i<n;i++)
		read(a[i]);
	create(1, 0, n-1);
	ll q;
	read(q);
	// for(ll i=1;i<10;i++)
	// 	cout << t[i].a << " " << t[i].b << "\n";
	while(q--){
		cin.ignore(256, '\n');
		char ch;
		cin >> ch;
		ll x, y;
		read(x, y);
		if(ch == 'U'){
			update(1, 0, n-1, x-1, y);
			// cout << q << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n";
			// for(ll i=1;i<10;i++)
			// 	cout << t[i].a << " " << t[i].b << "\n";
		}
		else{
			paired ans = query(1, 0, n-1, x-1, y-1);
			cout << ans.a + ans.b << "\n";
		}
	}

	end_clock();							//This too.
	return 0;
}