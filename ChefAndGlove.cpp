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
	ll l[n], g[n];
	for(ll i=0;i<n;i++)
		read(l[i]);
	for(ll i=0;i<n;i++)
		read(g[i]);
	ll fflag = 1, bflag = 1;

	for(ll i=0;i<n;i++)
		if(g[i] < l[i])
			fflag = 0;

	for(ll i=0;i<n;i++)
		if(g[n-i-1] < l[i])
			bflag = 0;

	if(fflag == 1 && bflag == 1){
		cout << "both\n";
		return;
	}
	if(fflag == 1){
		cout << "front\n";
		return;
	}
	if(bflag == 1){
		cout << "back\n";
		return;
	}
	else{
		cout << "none\n";
		return;
	}
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