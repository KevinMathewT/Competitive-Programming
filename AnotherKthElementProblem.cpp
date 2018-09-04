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

te(){
	ll i, n;
	read(n);
	ll a[n];
	map<ll, ll> sub;
	F0(i, n){ read(a[i]); sub[a[i]] = 0; };
	for(ll i=0;i<n-1;i++){
		ll l;
		ll r;
		for(ll j=i-1;i>=0;j--){
			if(a[j]>a[i])
				l++;
			else
				break;
		}
		for(ll j=i+1;i<=n;j++){
			if(a[j]>a[i])
				r++;
			else
				break;
		}
		sub[a[i]] += (((l+r+1)*(l+r+2))/2) - ((l*(l+1))/2) - ((r*(r+1))/2);
	}
	sort(a, a+n);
	vector<ll> v;
	v.push_back(a[0]);
	F1(i, n-1)
		if(a[i]!=v[v.size()-1])
			v.push_back(a[i]);
	ll cumf[v.size()];
	cumf[0]=v[0];
	F1(i, v.size-1)
		cumf[i]=cumf[i-1]+v[i];
	
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