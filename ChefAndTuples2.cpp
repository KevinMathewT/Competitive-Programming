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

void te(){
	ll n, a, b, c;
	read(n, a, b, c);

	ll count = 0;
	for(ll i=1;i<=sqrt(n);i++){
		if(n%i == 0){
			ll e = i;
			ll f = (n / i);
			for(ll j=1;j<=sqrt(n / e);j++){
				if((n / e) % j == 0){
					ll x = (n / e);
					ll g = j;
					ll h = (x / j);
					ll k = n / (e * g);
					ll l = n / (e * h);
					// cout << "Hey\n";
					if(e <= a && g <= b && k <= c){ count++;} //cout << e << " " << g << " " << k << "\n";}
					// else cout << "Na\n";
					if(e <= a && h <= b && l <= c){ count++;} //cout << e << " " << h << " " << l << "\n";}
					// else cout << "Na\n";
					if((g == h || k == l) && e <= a && g <= b && k <= c && h <= b && l <= c) count--;
				}
			}
			if(f != e)
			for(ll j=1;j<=sqrt(n / f);j++){
				if((n / f) % j == 0){
					ll x = (n / f);
					ll g = j;
					ll h = (x / j);
					ll k = n / (f * g);
					ll l = n / (f * h);
					// cout << "Hey\n";
					if(f <= a && g <= b && k <= c){ count++;} //cout << e << " " << g << " " << k << "\n";}
					// else cout << "Na\n";
					if(f <= a && h <= b && l <= c){ count++;} //cout << e << " " << h << " " << l << "\n";}
					// else cout << "Na\n";
					if((g == h || k == l) && f <= a && g <= b && k <= c && h <= b && l <= c){ count--;} //cout << "Minus\n";}
				}
			}
		}
	}

	// cout << "---------------------------\n";
	cout << count << "\n";
	// cout << "---------------------------\n";
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