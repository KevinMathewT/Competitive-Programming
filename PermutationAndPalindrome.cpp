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
	string s;
	getline(cin, s);
	vector<ll> v[26];
	for(ll i=0;i<s.size();i++)
		v[s[i]-'a'].push_back(i+1);
	ll a[s.size()];
	ll k = 0, co = 0;

	for(ll i=0;i<26;i++)
		if(v[i].size()%2 == 1)
			co++;
	if(co > 1){
		cout << -1 << "\n";
		return;
	}

	// for(ll i=0;i<26;i++){
	// 	if(v[i].size() == 0)
	// 		continue;
	// 	for(ll j=0;j<v[i].size();j++)
	// 		cout << v[i][j] << " ";
	// 	cout << "\n";
	// }
	for(ll i=0;i<26;i++){
		ll len = v[i].size();
		if(len % 2 != 0) len--;
		for(ll j=0;j<len;j+=2){
			a[k] = v[i][j];
			a[s.size()-1-(k)] = v[i][j+1];
			k++;
		}
	}
	for(ll i=0;i<26;i++)
		if(v[i].size()%2 == 1)
			a[s.size()/2] = v[i][v[i].size()-1];
	for(ll i=0;i<s.size();i++)
		cout << a[i] << " ";
	cout << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll t;
	read(t);
	cin.ignore(256, '\n');
	while(t--) te();

	end_clock();							//This too.
	return 0;
}