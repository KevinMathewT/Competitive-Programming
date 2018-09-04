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

#define ten 10000

ll fact[ten+10];

void fillFact(){
	for(ll i=0;i<ten;i++)
		fact[i] = i;
	for(ll i=2;i<ten;i++){
		if(fact[i] == i)
			for(ll j=i*i;j<ten;j+=i)
				if(fact[j] == j)
					fact[j] = i;
	}
	for(ll i=2;i<30;i++)
		cout << i << " " << fact[i] << "\n";
}

void te(){
	ll n, a, b, c, count = 0;
	read(n, a, b, c);
	
	for(ll i=1;i<=sqrt(n) && i<=a;i++){
		if(n%i == 0){
			for(ll j=1;j<=sqrt(n/i) && j<=b;j++)
				if()
		}
	}

	cout << count << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	fillFact();
	ll T;
	read(T);
	while(T--) te();

	end_clock();							//This too.
	return 0;
}