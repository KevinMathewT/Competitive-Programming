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
	cin >> s;

	map<ll, vector<ll> > m;

	for(ll i=0;i<s.length();i++){
		ll c = s[i] - '0';
		m[c].push_back(i);
	}

	for(ll i=0;i<10;i++){
		for(ll j=0;j<m[i].size();j++)
			cout << m[i][j] << " ";
		cout << "\n";
	}

	ll v[s.length()+5];
	for(ll i=0;i<s.length()+5;i++)
		v[i] = 0;
	queue< pair<ll, ll> > q;
	q.push(make_pair(0, 0));

	while(!q.empty()){
		pair<ll, ll> p = q.front();
		q.pop();

		if(p.first == s.length()-1){
			cout << p.second << "\n";
			return;
		}

		ll dig = s[p.first]-'0';
		if(v[dig] != 1)
			q.push(make_pair(m[dig][m[dig].size()-1], p.second+1));
		v[s[p.first]-'0'] = 1;

		q.push(make_pair(p.first+1, p.second+1));
		if(p.first != 0)
			q.push(make_pair(p.first-1, p.second+1));
	}
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