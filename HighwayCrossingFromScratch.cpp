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
	ll n; ld s, y; cin >> n >> s >> y;
	ld v[n], d[n], p[n], c[n];

	for(ll i=0;i<n;i++) cin >> v[i];
	for(ll i=0;i<n;i++){
		cin >> d[i];
		if(d[i] == 0) d[i] = -1;
	}
	for(ll i=0;i<n;i++) cin >> p[i];
	for(ll i=0;i<n;i++) cin >> c[i];
	cout << fixed << setprecision(6);

	ld ct = (y / s), dx = 1e-6, ans = 0.0;
	for(ll i=0;i<n;i++){
		ld time = 0.0;
		ld bfront = p[i];
		ld bback = p[i] - (d[i]*c[i]);
		ld afront = p[i] + (d[i]*v[i]*ct);
		ld aback = p[i] + (d[i]*v[i]*ct) - (d[i]*c[i]);
		if(d[i] == 1 && bfront > dx && bback > dx)
			time = ct;
		else if(d[i] == -1 && bfront < (0.0-dx) && bback < (0.0-dx))
			time = ct;
		else if(d[i] == 1 && bfront < (0.0-dx) && bback < (0.0-dx)){
			ld t = (abs(bfront) - dx) / v[i];
			if(t <= ct)
				time = (abs(bback) + dx)/ v[i] + ct;
			else
				time = ct;
		}
		else if(d[i] == -1 && bfront > dx && bback > dx){
			ld t = (abs(bfront) - dx) / v[i];
			if(t <= ct)
				time = (abs(bback) + dx) / v[i] + ct;
			else
				time = ct;
		}
		else{
			time = (abs(bback) + dx) / v[i] + ct;
		}
		for(ll j=i+1;j<n;j++)
			p[j] = p[j]+(d[j]*v[j]*time);
		ans = ans + time;
		// cout << bfront << "\n";
	}
	cout << ans << "\n";
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