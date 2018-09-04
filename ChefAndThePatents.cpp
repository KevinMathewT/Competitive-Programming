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
	ll n, i, m, x, k, e = 0, o = 0;
	read(n, m, x, k);
	cin.ignore(256, '\n');
	string s;
	getline(cin, s);
	F0(i, s.size()){
		if(s[i] == 'E')
			e++;
		if(s[i] == 'O')
			o++;
	}
	ll ew = min(e, x);
	ll ow = min(o, x);
	ll z = 0;
	ll em = floor(m/2.0);
	ll om = ceil(m/2.0);
	ll a = min(em*ew, e);
	ll b = min(om*ow, o);
	cout << em << " " << om << "\n";
	if(a+b >= n)
		cout << "yes\n";
	else
		cout << "no\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll t;
	read(t);
	while(t--) te();

	end_clock();							//This too.
	return 0;
}