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

ll vi[100000+10];
vector<ll> v[100000+10];

ll dfs(ll n){
	if(vi[n] == 1)
		return 0;
	vi[n] = 1;
	ll ans = 1;
	for(ll i=0;i<v[n].size();i++)
		ans += dfs(v[n][i]);
	return ans;
}

void te(){
	ll n, m;
	read(n, m);
	for(ll i=0;i<=100000;i++){
		v[i].clear();
		vi[i] = 0;
	}
	for(ll i=0;i<m;i++){
		ll r, s;
		read(r, s);
		v[r-1].push_back(s-1);
		v[s-1].push_back(r-1);
	}
	for(ll i=0;i<n;i++)
		vi[i]=0;
	ll com = 0, ans2 = 1;
	for(ll i=0;i<n;i++){
		if(vi[i] == 0){
			com++;
			ans2 *= dfs(i);
		}
	}

	cout << com << " " << ans2 << "\n";
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