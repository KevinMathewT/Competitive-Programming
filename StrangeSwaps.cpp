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
	ll n, k;
	read(n, k);
	k++;
	ll a[n];
	for(ll i=0;i<n;i++)
		read(a[i]);

	if(k <= (n/2)){
		sort(a, a+n);
		for(ll i=0;i<n;i++)
			cout << a[i] << " ";
		cout << "\n";
	}
	else if(k >= n){
		for(ll i=0;i<n;i++)
			cout << a[i] << " ";
		cout << "\n";
	}
	else{
		ll s = (n-k);
		ll b[2*s];
		ll c = 0;
		for(ll i=0;i<s;i++)
			b[c++] = a[i];
		for(ll i=n-1;i>n-s-1;i--)
			b[c++] = a[i];
		sort(b, b+2*s);
		for(ll i=0;i<s;i++)
			cout << b[i] << " ";
		for(ll i=s;i<n-s;i++)
			cout << a[i] << " ";
		for(ll i=s;i<2*s;i++)
			cout << b[i] << " ";
		cout << "\n";
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

	te();

	end_clock();							//This too.
	return 0;
}