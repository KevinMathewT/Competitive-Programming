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
#define SIZE 5000000

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

ll p, q, c, m, d, MOD = 1e9+7;
pair<ll, ll> pr[3050];
map<ll, map<ll, ll> > dp;
map<ll, map<ll, ll> > vis;


ll DP(ll g, ll b){
	// cout << g << " " << b << "\n";
	if(vis[g][b] == 1) return dp[g][b];
	vis[g][b] = 1;
	pair<ll, ll> piar;
	piar.first = g;
	piar.second = b;
	if(binary_search(pr, pr+m, piar)) return dp[g][b] = 0;
	ll rep = g - b;
	ll dep = g + b;
	if(dep == d) return dp[g][b] = 1;
	if(rep > c){
		ll good = 0, bad = 0;
		if(g < p)
			good = DP(g+1, b);
		if(b < q)
			bad = DP(g, b+1);
		// cout << g << " " << b << " " << good << " " << bad << "\n";
		return dp[g][b] = ((good % MOD) + (bad % MOD)) % MOD;
	}
	if(rep <= c){
		ll good = 0;
		good = DP(g+1, b);
		return dp[g][b] = ((good % MOD));
	}
}


void te(){
	read(p, q, c, m);
	d = (p + q);

	for(ll i=0;i<m;i++)
		read(pr[i].first, pr[i].second);
	sort(pr, pr+m);

	cout << DP(0, 0) << "\n";
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