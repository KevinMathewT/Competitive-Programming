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

ll a[10100], b[10100], v[10100], p[10100];

ll dfs(ll n, ll tof){
	if(v[n] == 1){
		if(tof == 1) return 1;
		else return 0;
	}

	v[n] = 1;
	if(tof == 1)
		dfs(a[n], b[n]);
	else
		dfs(a[n], 1-b[n]);
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this
	// start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	while(true){
		ll n;
		read(n);
		if(n == 0) break;

		for(ll i=1;i<=n;i++){
			v[i] = 0;
			read(a[i]);
			string s; cin >> s;
			if(s.compare("true") == 0) b[i] = 1;
			else b[i] = 0;
		}

		ll flag = 1;
		for(ll i=1;i<=n;i++){
			if(v[i] == 0){
				if(dfs(i, 1) == 0){
					flag = 0; break;
				}
			}
		}
		if(flag == 0)
			cout << "PARADOX\n";
		else
			cout << "NOT PARADOX\n";
	}

	// end_clock();							//This too.
	return 0;
}