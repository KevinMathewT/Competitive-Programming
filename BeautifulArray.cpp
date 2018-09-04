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
	ll n, i;
	read(n);
	ll a[n];
	F0(i, n) read(a[i]);
	ll one=0, two=0, three=0, tot=0;
	F0(i, n){
		if(a[i] % 4 == 1)
			one++;
		if(a[i] % 4 == 2)
			two++;
		if(a[i] % 4 == 3)
			three++;		
	}
	tot += min(one, three);
	ll val = min(one, three);
	one -= val;
	three -= val;
	tot += two / 2;
	two -= floor(two / 2) * 2;

	ll play = one == 0 ? three : one;

	if(two == 1){
		tot += 2;
		play -= 2;
	}

	if(play % 4 != 0){
		cout << "-1\n";
		return;
	}

	tot += (play / 4) * 3;
	cout << tot << "\n";
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
	cin >> T;
	while(T--) te();

	end_clock();							//This too.
	return 0;
}