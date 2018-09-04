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

void te(){
	ld px, py, pz, qx, qy, qz, dx, dy, dz, cx, cy, cz, r;
	cin >> px >> py >> pz >> qx >> qy >> qz >> dx >> dy >> dz >> cx >> cy >> cz >> r;

	ld a = px, b = py, c = pz;
	ld x = cx, y = cy, z = cz;

	ld low = 0; ld high;
	if(((a - x) * dx + (b - y) * dy + (c - z) * dz) != 0)
		high = ((qx - a) * (x - a) + (qy - b) * (y - b) + (qz - c) * (z - c)) / ((a - x) * dx + (b - y) * dy + (c - z) * dz);
	else high = 1e9 + 1000;

	// cout << high << "\n";

	for(ll i=0;i<1000;i++){
		ld mid = (low + high) / 2;

		// cout << "mid : " << mid << "\n";
		a = px, b = py, c = pz;
		ld d = qx + mid * dx, e = qy + mid * dy, f = qz + mid * dz;
		x = cx, y = cy, z = cz;

		// cout << a << " " << b << " " << c << " -\n";
		// cout << d << " " << e << " " << f << " --\n";

		ld t = ((a - x)*(a - d) + (b - y)*(b - e) + (c - z)*(c - f)) / ((d - a) * (d - a) + (e - b) * (e - b) + (f - c) * (f - c));

		// cout << t << "-\n";

		ld p = a * (1 - t) + d * t;
		ld q = b * (1 - t) + e * t;
		ld qwe = c * (1 - t) + f * t;

		// cout << p << " " << q << " " << r << "\n";

		ld dist = sqrt((p - x) * (p - x) + (q - y) * (q - y) + (qwe - z) * (qwe - z));

		// cout << dist << " --\n-------------------\n";

		if(dist < r)
			low = mid;
		else if(dist == r){
			low = mid;
			break;
		}
		else
			high = mid;
	}

	cout << abs(low) << "\n";

}

int main()
{
	freopen("input1.txt", "r", stdin);		//Comment
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