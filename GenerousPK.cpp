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
double dx = 0.000001;

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

double timeTaken(double midx, double x, double y, double v){
	return (sqrt((y*y) + (midx - x) * (midx - x))) / v;
}

void te(){
	double xs, ys, s1, xd, yd, s2;
	cin >> xs >> ys >> s1 >> xd >> yd >> s2;
	double l = 0;
	ll i;
	double u = max(xs, xd) - min(xs, xd);
	double ut = max(xs, xd) - min(xs, xd);
	//cout << l << " " << u << "\n";
	double mid = (l + u) / 2.00000;
	double val, valdx;
	F0(i, 10000){
		mid = (l + u) / 2.0000;
		val = timeTaken(mid, 0, ys, s1) + timeTaken(mid, ut, yd, s2);
		valdx = timeTaken(mid+dx, 0, ys, s1) + timeTaken(mid+dx, ut, yd, s2);
		if(valdx > val)
			u = mid;
		else if(valdx < val)
			l = mid;
		else
			break;
	}
	cout << val << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.
	cout << fixed << setprecision(6);

	ll t;
	read(t);
	while(t--) te();

	end_clock();							//This too.
	return 0;
}