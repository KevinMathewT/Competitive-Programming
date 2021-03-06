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
	string s, t, u;
	cin >> s >> t >> u;

	ll a[26], b[26];
	for(ll i=0;i<26;i++)
		a[i] = b[i] = 0;
	for(ll i=0;i<s.length();i++)
		a[s[i]-'A']++;

	for(ll i=0;i<t.length();i++)
		a[t[i]-'A']++;

	for(ll i=0;i<u.length();i++)
		b[u[i]-'A']++;

	for(ll i=0;i<26;i++){
		// cout << a[i] << " " << b[i] << "\n";
		if(a[i] != b[i]){
			cout << "NO" << "\n";
			exit(0);
		}
	}

	cout << "YES\n";
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