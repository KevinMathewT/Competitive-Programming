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

ld px, py, pz, qx, qy, qz, dx, dy, dz, cx, cy, cz, rad;

ll doesIntersect(ld a, ld b, ld c, ld p, ld q, ld r){
	ld A = p * p + q * q + r * r;
	ld B = 2 * (p * (a - cx) + q * (b - cy) + r * (c - cz));
	ld C = (a - cx) * (a - cx) + (b - cy) * (b - cy) + (c - cz) * (c - cz) - rad * rad;


	// cout << A << " " << B << " " << C << "\n";
	ld disc = B * B - 4 * C;

	// cout << disc << "\n";

	if(disc < 0) return 1;
	else return -1;
}

void te(){
	cin >> px >> py >> pz >> qx >> qy >> qz >> dx >> dy >> dz >> cx >> cy >> cz >> rad;

	ld a = px, b = py, c = pz;
	ld x = cx, y = cy, z = cz;

	ld low = 0; ld high;
	// if(((a - x) * dx + (b - y) * dy + (c - z) * dz) != 0)
	// 	high = ((qx - a) * (x - a) + (qy - b) * (y - b) + (qz - c) * (z - c)) / ((a - x) * dx + (b - y) * dy + (c - z) * dz);
	// else 
		high = 1e9 + 1000;

	// cout << high << "\n";

	for(ll i=0;i<1000;i++){
		ld mid = (low + high) / 2;

		// cout << "mid : " << mid << "\n";
		a = px, b = py, c = pz;
		ld d = qx + mid * dx, e = qy + mid * dy, f = qz + mid * dz;
		ld dd = qx + (mid + 1e-3) * dx, de = qy + (mid + 1e-3) * dy, df = qz + (mid + 1e-3) * dz;
		x = cx, y = cy, z = cz;
		ld j = a - d, k = b - e, l = c - f, m = sqrt(j*j + k*k + l*l);
		ld dj = a - dd, dk = b - de, dl = c - df, dm = sqrt(dj*jd + dk*dk + dl*dl);

		ld boolean = doesIntersect(a, b, c, (a - d) / m, (b - e) / m, (c - f) / m);

		if(boolean > 0)
			high = mid;
		else
			low = mid;
		// cout << "---------\n";
	}

	for(ll i=0;i<1000;i++){
		ld mid = (low + high) / 2;

		// cout << "mid : " << mid << "\n";
		a = px, b = py, c = pz;
		ld d = qx + mid * dx, e = qy + mid * dy, f = qz + mid * dz;
		x = cx, y = cy, z = cz;
		ld j = a - d, k = b - e, l = c - f, m = sqrt(j*j + k*k + l*l);

		ld boolean = doesIntersect(a, b, c, (a - d) / m, (b - e) / m, (c - f) / m);

		if(boolean > 0)
			high = mid;
		else
			low = mid;
		// cout << "---------\n";
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
	cout << fixed << setprecision(10);

	ll T;
	read(T);
	while(T--) te();

	end_clock();							//This too.
	return 0;
}