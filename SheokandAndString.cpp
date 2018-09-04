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
	map<string, ll> ms;
	string s[n]; for(ll i=0;i<n;i++){ cin >> s[i]; ms[(string)s[i]] = 1; }
	// ll q; read(q);
	// ll r[q];
	// string p[q];
	// for(ll i=0;i<q;i++)
	// 	cin >> r[i] >> p[i];

	// map<string, vector<ll> > m;

	// for(ll i=0;i<n;i++)
	// 	for(ll j=0;j<s[i].length();j++)
	// 		m[s[i].substr(0, j+1)].push_back(i);

	// ll q; read(q);
	// while(q--){
	// 	ll r; read(r);
	// 	string p; cin >> p;
	// 	ll pos = -1;

	// 	for(ll i=p.length();i>0;i--){
	// 		if(m.find(p.substr(0, i)) == m.end())
	// 			continue;
	// 		ll flag = 1;
	// 		string t = p.substr(0, i);
	// 		if(m[t][0] > r) continue;
	// 		if(ms[t] == 1){ cout << t << "\n"; break; }
	// 		ll count = 0;
	// 		while(true){
	// 			count++;
	// 			for(int j=0;j<26;j++){
	// 				string u = t.append(((char)('a' + j)) + "");
	// 				if(m.find(u) != m.end() && m[u][0] <= r){
	// 					if(!(ms[u] == 1)){
	// 						cout << u << "\n";
	// 						flag = 1;
	// 						break;
	// 					}
	// 					else
	// 						t = u;
	// 				}
	// 				if(count >= 20){
	// 					cout << "BROKEN\n";
	// 					break;
	// 				}
	// 			}
	// 		}
	// 		if(flag == 1)
	// 			break;
	// 		else cout << "\n";
	// 	}
	// }	
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output1.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// te();

	end_clock();							//This too.
	return 0;
}