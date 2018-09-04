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
#define SZ(x) ((ll)x.size())

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

ll a[5000], dpmin[5000][5000], prefix[5000];

ll DP(ll n, ll k){
	if(k == 1)
		return prefix[n-1];
	for(ll )
}

int main()
{
	freopen("input1.txt", "r", stdin);		//Comment
	freopen("output1.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll n, k, i;
	read(n, k);
	F0(i, n) read(a[i]);


	for(ll i=0;i<n;i++){
		ll min = LLONG_MAX;
		for(ll j=i;j<=n;j++){
			if(j != i)
				dpmin[i][j] = min(dpmin[i][j-1], a[j]);
			else
				dpmin[i][j] = a[j];
		}
	}

	prefix[0]=a[0];
	for(ll i=1;i<n;i++)
		prefix[i] = prefix[i-1] + a[i];



	end_clock();							//This too.
	return 0;
}