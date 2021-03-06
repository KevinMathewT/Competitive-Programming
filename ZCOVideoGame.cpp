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

	ll n, h, i;
	read(n, h);
	ll a[n];
	F0(i, n) read(a[i]);
	cin.ignore(256, '\n');
	string s;
	getline(cin, s);
	ll p=0, st=0;
	cout << s << "\n";
	for(char * i = a; i<=a.){
		cout << "Reached Here" << "\n";
		if(s[i] == ' ')
			continue;
		ll w = aoll(s, i, i+1);
		cout << w << "\n";
		if(w == 1 && p > 0)
			p--;
		if(w == 2 && p < n-1)
			p++;
		if(w == 3 && a[p] > 0 && st == 0){
			a[p]--;
			st = 1;
		}
		if(w == 4 && a[p] < h && st == 1){
			a[p]++;
			st = 0;
		}
	}

	F0(i, n) cout << a[i] << " ";

	end_clock();							//This too.
	return 0;
}