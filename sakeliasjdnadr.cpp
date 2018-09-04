#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
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

void te(){
	ll a, b, x, y; read(a, b);
	vector<ll> va, vb, vx, vy;

	for(ll i=1;i<sqrt(a);i++)
		if(a%i == 0){
			va.push_back(i);
			va.push_back(a/i);
		}
	for(ll i=1;i<sqrt(b);i++)
		if(b%i == 0){
			vb.push_back(i);
			vb.push_back(b/i);
		}
	if(pow(sqrt(a), 2) == a)
		va.push_back(sqrt(a));
	if(pow(sqrt(b), 2) == b)
		va.push_back(sqrt(b));

	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());

	ll pos = 0;
	for(ll i=0;i<va.size();i++){
		ll c = 1, k;
		for(k=1;k<va.size();k++){
			if(va[k] == va[k-1])
				c++;
			else
				break;
		}
		c %= 3;
		ll d = 0;
		for(ll j=pos;j<vb.size();j++){
			if(vb[j] == va[i]){
				d++; pos++;
			}
			else
				break;
		}
		d %= 3;
		ll f = va[i];

		cout << "-----------------------------\n";

		if(c == 1 && d == 0){ x *= (f*f*f); y *= (f*f); vx.push_back(3); vy.push_back(2); }
		if(c == 0 && d == 1){ x *= (f*f); y *= (f*f*f); vx.push_back(2); vy.push_back(3); }
		if(c == 2 && d == 1){ x *= (f*f); y *= (f); vx.push_back(2); vy.push_back(1); }
		if(c == 1 && d == 2){ x *= (f); y *= (f*f); vx.push_back(1); vy.push_back(2); }
		if(c == 2 && d == 0){ x *= (pow(f, 6)); y *= (pow(f, 4)); vx.push_back(6); vy.push_back(4); }
		if(c == 0 && d == 2){ x *= (pow(f, 4)); y *= (pow(f, 6)); vx.push_back(4); vy.push_back(6); }
		i = k + 1;
	}

	while(pos < vb.size()){
		ll d = 0;
		for(ll j=pos;j<vb.size();j++){
			if(vb[j] == vb[j-1]){
				d++; pos++;
			}
			else
				break;
		}
		d %= 3;
		ll f = vb[pos-1];

		if(d == 1){ x *= (f*f); y *= (f*f*f); vx.push_back(2); vy.push_back(3); }
		if(d == 2){ x *= (pow(f, 4)); y *= (pow(f, 6)); vx.push_back(4); vy.push_back(6); }
	}

	ll ans = 1;
	if(x <= y)
		for(ll i=0;i<vx.size();i++)
			ans *= (vx[i]+1);
	else
		for(ll i=0;i<vy.size();i++)
			ans *= (vy[i]+1);

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