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
	ll n, m, k;
	read(n, m, k);

	if(k < n){
		cout << k + 1 << " 1\n";
		return;
	}

	k = k - n;
	m--;

	ll x = k % m;
	ll y = k / m;

	// cout << k << " " << x << " " << y << "\n";

	if(y % 2 == 0){
		cout << (n - y) << " " << 2 + x;
	}

	else{
		cout << (n - y) << " " << m + 1 - x;
	}
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