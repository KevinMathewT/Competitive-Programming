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


string s[10000+10];
ll dp[10000+10][11][11];

ll DynP(ll i, char st, char en, ll n){
	if(i > n-1)
		return 0;
	if(dp[i][st-'0'][en-'0'] != 0)
		return dp[i][st-'0'][en-'0'];

	ll sum1=0, sum2=0;
	dp[i+1][st-'0'][s[i][s[i].length()-1]-'0'] = DynP(i+1, st, s[i][s[i].length()-1], n);
	ll case1 = dp[i+1][st-'0'][s[i][s[i].length()-1]-'0'];
	dp[i+1][s[i][0]-'0'][en-'0'] = DynP(i+1, s[i][0], en, n);
	ll case2 = dp[i+1][s[i][0]-'0'][en-'0'];

	if(s[i][0] == en)
		sum1 = s[i].length() - 1 + case1;
	else
		sum1 = s[i].length() + case1;


	if(s[i][s[i].length()-1] == st)
		sum2 = s[i].length() - 1 + case2;
	else
		sum2 = s[i].length() + case2;

	//cout << sum1 << " " << sum2 << "\n";
	return min(sum1, sum2);
}

void te(){
	ll n; read(n);
	// cout << n << "\n";
	cin.ignore(256, '\n');
	for(ll i=0;i<n;i++)
		cin >> s[i];
	// for(ll i=0;i<n;i++)
	// 	cout << s[i] << "\n";
	// cout << s[0][0] << " " << s[0][s[0].length()-1] << "\n";

	cout << s[0].length() + DynP(1, s[0][0], s[0][s[0].length()-1], n) << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	read(T);
	while(T--) te();

	end_clock();							//This too.
	return 0;
}