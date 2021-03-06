#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

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

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.

	while(true){
		ll n, i;
		read(n);
		if(n == 0)
			return 0;
		cin.ignore(256, '\n');
		string cur[n];
		F0(i, n) cin >> cur[i];
		ll e;
		read(e);
		cin.ignore(256, '\n');
		map<string, vector< pair<string, ld> > > m;
		while(e--){
			std::string a, b, c;
			cin >> a >> b >> c;
			ld d, e;
			ll f;
			f = c.find(":");
			d = stoll(c.substr(0, c.find(":")));
			e = stoll(c.substr(f+1));
			m[a].push_back(make_pair(b, e/d));
		}
		map<string, vector< pair<string, ld> > >::iterator it;
		for(it=m.begin();it!=m.end();it++)
			cout << it->first << it->second.first << it->second.second;
	}

	end_clock();							//This too.
	return 0;
}