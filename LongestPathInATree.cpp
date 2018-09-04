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

ll n, mx = 0; ll farthest = 0;
vector<ll> al[10000];
ll v[10000];

void dfs(ll node, ll dist){
	// cout << node << " " << dist << "--\n";
	v[node] = 1;
	if(dist > mx){
		mx = dist;
		farthest = node;

		// cout << mx << " " << farthest << "----\n";
	}
	// cout << al[node].size() << "-\n";
	for(ll i=0;i<al[node].size();i++){
		if(v[al[node][i]] != 1)
			dfs(al[node][i], dist+1);
	}

	return;
}

void te(){
	read(n);

	for(ll i=0;i<n;i++)
		v[i] = 0;
	for(ll i=0;i<n-1;i++){
		ll u, vee; read(u, vee);
		al[u].push_back(vee);
		al[vee].push_back(u);
	}

	mx = 0; farthest = 1;

	dfs(1, 0);

	mx = 0;
	for(ll i=0;i<n;i++)
		v[i] = 0;
	
	dfs(farthest, 0);

	cout << mx << "\n";
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