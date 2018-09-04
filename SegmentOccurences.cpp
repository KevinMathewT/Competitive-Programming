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
	ll n, m, q;
	read(n, m, q);

	cin.ignore(256, '\n');
	string s; cin >> s;
	string t; cin >> t;
	// cout << s << "\n";
	// cout << t << "\n";

	map<string, vector<pair<ll, ll> > > mp;

	for(ll i=0;i<=s.length()-1;i++)
		for(ll j=0;j+i<=s.length();j++)
			mp[s.substr(i, j)].push_back(make_pair(i, i+j));

	vector<pair<ll, ll> > v;
	if(mp.find(t) != mp.end())
		v = mp[t];

	// // cout << " sdf'ms;dlf - " << v.size() << "\n";
	// for(int i=0;i<v.size();i++)
	// 	cout << v[i].first << " " << v[i].second << "\n";

	for (ll i=0;i<q;i++){
		ll a = 0, b = 0;
		cin >> a;
		cin >> b;
		a--;

		if(v.size() == 0){
			cout << 0 << "\n";
			continue;
		}
		
		ll count = 0;
		for(int i=0;i<v.size();i++){
			if(v[i].first >= a && v[i].second <=b)
				count++;
		}
		cout << count << "\n";
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this
	// start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	// end_clock();							//This too.
	return 0;
}