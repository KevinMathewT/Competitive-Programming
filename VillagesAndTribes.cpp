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
	string s; cin >> s;
	ll a = 0;
	ll b = 0;

	for(ll i=0;i<s.length();i++){
		if(s[i] == 'A')
			a++;
		if(s[i] == 'B')
			b++;
	}

	if(a == 0 && b == 0){ cout << "0 0\n"; return; }
	if(a == 1 && b == 0){ cout << "1 0\n"; return; }
	if(a == 0 && b == 1){ cout << "0 1\n"; return; }
	if(a == 1 && b == 1){ cout << "1 1\n"; return; }


	ll posa = -1, posb = -1;
	ll fa = s.length(), fb = s.length();
	ll ansa = 0, ansb = 0;
	for(ll i=0;i<s.length();i++){
		if(s[i] == 'A' && fa == s.length()) fa = i;
		if(s[i] == 'B' && fb == s.length()) fb = i;
	}
	// cout << fa << " " << fb << "\n";
	for(ll i=fa+1;i<s.length();i++){
		if(s[i] == 'A' && fa != -1){ ansa += i - fa - 1; fa = i; }
		if(s[i] == 'A' && fa == -1){ fa = i; }
		if(s[i] == 'B') fa = -1;
	}
	ansa += a;
	for(ll i=fb+1;i<s.length();i++){
		if(s[i] == 'B' && fb != -1){ ansb += i - fb - 1; fb = i; }
		if(s[i] == 'B' && fb == -1){ fb = i; }
		if(s[i] == 'A') fb = -1;
	}
	ansb += b;

	cout << ansa << " " << ansb << "\n";
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
	cin.ignore(256, '\n');
	while(T--) te();

	end_clock();							//This too.
	return 0;
}