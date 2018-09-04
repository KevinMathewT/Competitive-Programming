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
	ll a[n+1][m+1];
	for(ll i=0;i<=n;i++)
		for(ll j=0;j<=m;j++)
			a[i][j] = 0;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
			read(a[i][j]);

	if(a[1][1] == -1)
		a[1][1] = 1;

	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++){
			if(i==0 && j==0)
				continue;
			if(a[i][j] == -1)
				a[i][j] = max(a[i-1][j], a[i][j-1]);
		}

	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
			if(a[i][j] < a[i-1][j] || a[i][j] < a[i][j-1]){
				cout << -1 << "\n";
				return;
			}

	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
				cout << a[i][j] << " ";
		}
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

	ll T;
	read(T);
	while(T--) te();

	end_clock();							//This too.
	return 0;
}