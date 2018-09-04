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
	ll n, m;
	read(n, m);
	ll s = ((n)*(n+1))/2;
	if(s == m && s != 1){
		cout << "No\n";
		return;
	}
	if(s == m && s == 1){
		cout << "Yes\n";
		return;
	}
	if(s % 2 == 0){
		if(m % 2 != 0){
			cout << "No\n";
			return;
		}
		ll s1 = (s/2)-(m/2);
		ll s2 = (s/2)+(m/2);
		if(__gcd(s1, s2) == 1)
			cout << "Yes\n";
		else cout << "No\n";
		return;
	}
	else{
		if(m % 2 == 0){
			cout << "No\n";
			return;
		}
		ll s1 = (s/2 + 1)+(m/2);
		ll s2 = (s/2)-(m/2);
		if(__gcd(s1, s2) == 1)
			cout << "Yes\n";
		else cout << "No\n";
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