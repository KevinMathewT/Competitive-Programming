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
	ll n;
	read(n);
	string s, t;
	// cin.ignore('\n', 256);
	cin >> s;
	cin >> t;

	// cout << s << "\n";
	// cout << t << "\n";

	ll zz = 0, zo = 0, oz = 0, oo = 0;

	for(ll i=0;i<s.length();i++){
		char fir = s[i];
		char sec = t[i];

		if(fir == '0' && sec == '0') zz++;
		if(fir == '0' && sec == '1') zo++;
		if(fir == '1' && sec == '0') oz++;
		if(fir == '1' && sec == '1') oo++;
	}

	// cout << oo << oz << zo << zz << "\n";

	ll tot = oo * zz + zz * oz + oz * zo;
	cout << tot << "\n";
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