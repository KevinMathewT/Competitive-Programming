#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <utility>

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

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll n;
	read(n);
	ll a[n];
	F0(i, n) read(a[i]);
	ll d=0, max=0, p=0, maxl = 0, l=0, pl = 0, maxpl = 0;
	F0(i, n){
		l++;
		//cout << i << " " << l << " " << d << " " << pl << " " << "\n";
		if(a[i] == 1)
			d++;
		if(a[i] == 2)
			d--;
		if(d > max){
			max = d;
			p = i+1;
		}
		if(d == 0){
			if(l > maxl){
				maxpl = pl;
				maxl = l;
			}
			pl = i+2;
			l = 0;
		}
	}

	cout << max << " " << p << " " << maxl << " " << maxpl;

	end_clock();							//This too.
	return 0;
}