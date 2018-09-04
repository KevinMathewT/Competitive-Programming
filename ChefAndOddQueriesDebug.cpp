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
	ll i, n;
	read(n);
	ll l[n], r[n];
	F0(i, n) read(l[i], r[i]);
	ll q, m;
	read(q);
	while(q--){
		ll c = 0;
		read(m);
		ll input;
		vector<ll> v;
		F0(i, m){
			read(input);
			v.push_back(input);
		}
		sort(v.begin(), v.end());
		vector<ll>::iterator low, up;
		F0(i, n){
			ll lower, upper;
			if(l[i]<=v[0])
				lower = 0;
			else{
				cout << "lower : " << upper_bound(v.begin(), v.end(), l[i]-1) - v.begin() << " ";
				lower = upper_bound(v.begin(), v.end(), l[i]-1) - v.begin();
			}
			if(r[i]>=v[m-1])
				upper = m;
			else{
				cout << "upper : " << upper_bound(v.begin(), v.end(), r[i]) - v.begin() << " ";
				lower = upper_bound(v.begin(), v.end(), r[i]) - v.begin();
			}
			cout << upper << " " << lower << "\n";
			if((upper-lower) % 2 == 1)
				c++;
		}
		cout << c << "\n";
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