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

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll size = 100;
	ll a[size], set[size];
	a[0] = 0; a[1] = 0;
	a[2] = 2; set[2]=1;

	for(ll i=2;i<size;i++)
		set[i] = 1;
	for(ll i=2;i<size;i++){
		if(set[i] == 1){
			for(ll j=i*i;j<size;j+=i)
				set[j]=0;
		}
	}

	ll temp = 2;
	for(ll i=3;i<size;i++){
		if(set[i] == 1)
			temp += i;
		a[i] = temp;
	}

	ll t;
	read(t);
	while(t--){
		ll l, r;
		read(l, r);
		cout << a[r] - a[l-1] << "\n";
	}

	end_clock();							//This too.
	return 0;
}