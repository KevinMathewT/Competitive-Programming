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
	ll n, q;
	read(n, q);

	ll a[n], b[n];
	for(ll i=0;i<n;i++){
		read(a[i]); 
		b[i] = a[i];
	}

	map<ll, ll> pos;
	for(ll i=0;i<n;i++)
		pos[a[i]] = i + 1;

	sort(b, b+n);
	
	map<ll, ll> greater;
	map<ll, ll> lesser;
	for(ll i=0;i<n;i++){
		greater[b[i]] = n - i - 1;
		lesser[b[i]] = i;
	}

	while(q--){
		ll x; read(x);

		ll p = pos[x];
		ll great = greater[x];
		ll less = lesser[x];

		ll l = 1, r = n;
		ll b = 0, s = 0, ub = 0, us = 0;
		while(l < r){
			ll mid = (l + r) / 2;

			if(p == mid)
				break;

			else if(p > mid){
				l = mid + 1;
				if(a[mid-1] > x){
					s++;
				}
				else
					us++;
			}

			else{
				r = mid - 1;
				if(a[mid-1] < x){
					b++;
				}
				else
					ub++;
			}
		}

		if(great < max(s, b) + ub || less < max(s, b) + us)
			cout << -1 << "\n";
		else
			cout << max(s, b) << "\n";
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

	ll t; read(t);
	while(t--) te();

	end_clock();							//This too.
	return 0;
}