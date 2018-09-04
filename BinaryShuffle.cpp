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

ll count1s(ll n){
	ll c = 0;
	while(n > 0){
		if(n & 1 != 0) c++;
		n = n >> 1;
	}
	return c;
}

void te(){
	ll a, b;
	cin >> a >> b;

	ll oa = count1s(a), ob = count1s(b-1);

	if(a == b)
		cout << 0 << "\n";
	else if(a == 0 && b == 1)
		cout << 1 << "\n";
	else if(b == 0 || b == 1)
		cout << -1 << "\n";
	else{
		if(oa == ob)
			cout << 1 << "\n";
		else if(oa < ob)
			cout << ob - oa + 1 << "\n";
		else
			cout << 2 << "\n";
	}
}

int main()
{
	freopen("input1.txt", "r", stdin);		//Comment
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