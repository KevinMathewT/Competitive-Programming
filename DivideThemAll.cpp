#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef float ld;
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

void te(){
	ll n;
	read(n);

	if(n == 0) return;

	if(n == 1 || n == 2){
		cout << "Yes\n";
		return;
	}

	ld a[n], b[n];

	for(ll i=0;i<n;i++){
		ll t; read(t);
		if(t == 0){
			ld r, x, y;
			cin >> r >> x >> y;
			a[i] = x;
			b[i] = y;
		}
		if(t == 1){
			ld j, z, c, d, e, f, g, h;
			cin >> j >> z >> c >> d;
			cin >> e >> f >> g >> h;

			a[i] = (j + c + e + g) / 4.0;
			b[i] = (z + d + f + h) / 4.0;
		}
	}

	ll flag = 1;
	ld m = abs((b[1] - b[0])/(a[1]-a[0]));
	for(ll i=2;i<n;i++){
		ld m1 = abs((b[i] - b[0])/(a[i]-a[0]));
		if(m1 != m){
			flag = 0;
			break;
		}
	}

	if(flag == 1)
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this
	// start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	// end_clock();							//This too.
	return 0;
}