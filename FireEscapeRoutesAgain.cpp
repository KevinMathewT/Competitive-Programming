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

ll n, m;
vector<ll> al[101000];
ll v[101000]; 
ll c = 0, prod = 1;

ll dfs(ll s){
	ll child = 1;

	for(ll i=0;i<al[s].size();i++){
		if(v[al[s][i]] == 0){
			v[al[s][i]] = 1;
			child += dfs(al[s][i]);
		}
	}

	return child;
}

void te(){
	read(n, m);
	c = 0, prod = 1;
	for(ll i=0;i<=n;i++){
		al[i].clear();
		v[i] = 0;
	}
	for(ll i=0;i<m;i++){
		ll u, v;
		read(u, v);
		al[u].push_back(v);
		al[v].push_back(u);
	}

	for(ll i=1;i<=n;i++){
		if(v[i] == 0){
			v[i] = 1;
			c++;
			// cout << i << " - " << dfs(i) << "\n";
			prod = ((prod % 1000000007) * (dfs(i) % 1000000007)) % 1000000007;
		}
	}

	cout << c << " " << prod << "\n";
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