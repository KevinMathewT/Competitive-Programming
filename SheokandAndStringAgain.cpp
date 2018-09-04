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
	ll n; read(n);
	unordered_map<string, ll> ms;
	string s[n]; for(ll i=0;i<n;i++){ cin >> s[i]; if(ms[(string)s[i]] == 0) ms[(string)s[i]] = i+1; }
	// cout << ms["abcd"] << "--\n";
	// ll q; read(q);
	// ll r[q];
	// string p[q];
	// for(ll i=0;i<q;i++)
	// 	cin >> r[i] >> p[i];

	unordered_map<string, vector<ll> > m;

	for(ll i=0;i<n;i++)
		for(ll j=0;j<=s[i].length();j++)
			m[s[i].substr(0, j)].push_back(i);

	ll q; read(q);

	vector<ll> v(0);
	while(q--){
		ll r; read(r);
		string p; cin >> p;

		ll flag = 0;
		for(ll i=p.length();i>=0;i--){
			string pre = p.substr(0, i);
			if(m[pre] == v)
				continue;
			if(m[pre][0] >= r)
				continue;
			flag = 1;
			ll sflag = 0;
			while(true){
				if(ms[pre] != 0 && ms[pre] <= r){
					cout << pre << "\n";
					sflag = 1;
					break;
				}
				for(ll j=0;j<26;j++){
					string t = pre + (char)(int('a') + j);
					if(m[t] != v && m[t][0] < r){
						pre = t;
						break;
					}
				}
			}
			if(sflag == 1)
				break;
		}
	}	
}

int main()
{
	freopen("input1.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	end_clock();							//This too.
	return 0;
}