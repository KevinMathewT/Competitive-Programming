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

ll b; ll inter;
vector<ll> al[2000+10];
ll v[2000+10], g[2000+10], it=0;

ll dfs(ll s){
	// cout << s << "----\n";
	for(ll i=0;i<al[s].size();i++){
		if(v[al[s][i]] == 1 && g[s] == g[al[s][i]])
			return 1;
	}

	ll ret = 0;

	for(ll i=0;i<al[s].size();i++){
		if(v[al[s][i]] == 0){
			v[al[s][i]] = 1;
			if(g[s] == 1) g[al[s][i]] = 2;
			else g[al[s][i]] = 1;
			ret += dfs(al[s][i]);
		}
	}

	// cout << s << " - s - " << ret << "\n";
	if(ret > 0)
		return 1;
	return 0;
}

void te(){
	read(b, inter);
	it++;
	for(ll i=0;i<=b;i++) al[i].clear();
	for(ll i=0;i<=b;i++) v[i] = 0;
	for(ll i=0;i<=b;i++) g[i] = 0;

	for(ll i=0;i<inter;i++){
		ll u, v; read(u, v);
		al[u].push_back(v);
		al[v].push_back(u);
	}

	for(ll i=1;i<=b;i++){
		if(v[i] == 0){
			v[i] = 1;
			g[i] = 1;
			ll flag = dfs(i);
			if(flag == 1){
				cout << "Scenario #" << it << ":\nSuspicious bugs found!\n";
				return;
			}
		}
	}

	cout << "Scenario #" << it <<":\nNo suspicious bugs found!\n";
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T; read(T);
	while(T--) te();

	end_clock();							//This too.
	return 0;
}