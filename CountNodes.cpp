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

ll cnt = 0;
void query(ll node, ll start, ll end, ll l, ll r){
	if(start < r || end > l)
		return;
	if(start >= l && end <= r){
		cnt++;
		return;
	}
	ll mid = (start + end)/2;
	query(2*node, start, mid, l, r);
	query(2*node+1, mid+1, end, l, r);
}

void te(){
	ll n;
	read(n);
	ll a[4*n];
	for(ll i=0;i<4*n;i++)
		a[i] = 0; 
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++){
			if(j >= i){
				query(1, 1, n, i, j);
				a[cnt]++;
				cnt = 0;
			}
		}

	for(ll i=0;i<4*n;i++)
		cout << a[i] << " ";
	cout << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	read(T);
	while(T--) te();

	end_clock();							//This too.
	return 0;
}