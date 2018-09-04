#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define F0(i,n) for (ll i = 0; i < n; i++)
#define F1(i,n) for (ll i = 1; i <= n; i++)
#define CL(a,x) memset(x, a, sizeof(x));
#define SZ(x) ((int)x.size())
#define printArray(i, a) F0(i, sizeof(a)/sizeof(a[0])){ cout << a[i] << " "; } cout << "\n";

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

ll F(string &s){
	ll i, c=0;
	for(i=1;i<s.length();i++) if(s[i] != s[i-1]) c++;
	return c+1;
}

std::map<string, ll> dp[5000+10];

ll DynamicP(string &s1, string &s2, ll m, ll n, ll l1, ll l2, ll *p1, ll *p2, ll *sf1, ll *sf2){
	cout << "Reached\n";
	if(m == l1)
		if(n == l2)
			return 0;
		else
			return sf2[m-1];
	if(n == l2)
		return sf1[n-1];
	ll mn = LLONG_MAX;
	for(ll i=n;i<=l2;i++){
		if(s2[i] == s1[m])
			mn = min(mn, p2[i]-p2[m]+DynamicP(s1, s2, m+1, n+1, l1, l2, p1, p2, sf1, sf2));
	}
	return mn;
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
	while(t--){
		ll n, m;
		read(n, m);
		string s1, s2, s3, s4;
		cin.ignore(256, '\n');
		getline(cin, s1);
		getline(cin, s2);
		s3=s1[0]; s4=s2[0];
		for(ll i=1;i<s1.length();i++)
			if(s1[i]!=s3[s3.length()-1])
				s3+=s1[i];
		for(ll i=1;i<s2.length();i++)
			if(s2[i]!=s4[s4.length()-1])
				s4+=s2[i];
		cout << s3 << " " << s4 << "\n";
		s1=s3;
		s2=s4;
		ll p1[n], p2[n], sf1[n], sf2[n];
		p1[0]=1; p2[0]=1;
		for(ll i=1;i<n;i++){
			if(s1[i]!=s1[i-1])
				p1[i]=p1[i-1]+1;
			else
				p1[i]=p1[i-1];
			if(s2[i]!=s2[i-1])
				p2[i]=p2[i-1]+1;
			else
				p2[i]=p2[i-1];
		}
		for(ll i=n-2;i>=0;i--){
			if(s1[i]!=s1[i+1])
				sf1[i]=sf1[i+1]+1;
			else
				sf1[i]=sf1[i+1];
			if(s2[i]!=s2[i+1])
				sf2[i]=sf2[i+1]+1;
			else
				sf2[i]=sf2[i+1];
		}
		printArray(i, p1);
		printArray(i, p2);
		printArray(i, sf1);
		printArray(i, sf2);
		cout << DynamicP(s1, s2, 0, 0, s1.length(), s2.length(), p1, p2, sf1, sf2);
	}

	end_clock();							//This too.
	return 0;
}