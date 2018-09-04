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
	ll s[n];
	for(ll i=0;i<n;i++)
		read(s[i]);

	ll pre[n+1], suf[n+1], fin[n+1];
	for(ll i=0;i<n+1;i++){
		pre[i]=0;
		suf[i]=0;
		fin[i]=0;
	}
	pre[0] = s[0];
	suf[n-1] = s[n-1];
	for(ll i=1;i<n;i++)
		pre[i] = s[i] + pre[i-1];
	for(ll i=n-2;i>=0;i--)
		suf[i] = s[i] + suf[i+1];


	// for(ll i=0;i<n;i++)
	// 	cout << pre[i] << " ";
	// cout << "\n";


	// for(ll i=0;i<n;i++)
	// 	cout << suf[i] << " ";
	// cout << "\n";


	for(ll i=0;i<n;i++){
		ll l=0, r=i-1;
		while(l < r){
			ll mid = (l+r)/2;
			if(suf[mid+1]-suf[i] > s[i])
				l = mid+1;
			else
				r = mid;
		}
		if(i != 0){
			fin[l] += 1;
			fin[i] += -1;
		}
		l = i+1; r = n;
		while(l < r){
			ll mid = (l+r)/2;
			if(pre[mid-1]-pre[i] > s[i])
				r = mid;
			else
				l = mid+1;
		}
		if(i != n-1){
			fin[i+1] += 1;
			fin[l] -= 1;
		}
	}

	// for(ll i=0;i<n;i++)
	// 	cout << fin[i] << " ";
	// cout << "\n";
	for(ll i=1;i<n;i++)
		fin[i] = fin[i] + fin[i-1];
	for(ll i=0;i<n;i++)
		cout << fin[i] << " ";
	cout << "\n";
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