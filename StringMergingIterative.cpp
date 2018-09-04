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
		//cout << s3 << " " << s4 << "\n";
		s1=s3;
		s2=s4;
		//cout << s1 << " " << s2 << "\n";
		n = s1.length();
		m = s2.length();
		ll fi = LLONG_MAX;
		ll mn = LLONG_MAX;
		for(ll i=0;i<n;i++){
			ll ans = i + m;
			ll ps = i;
			for(ll j=0;j<m;j++){
				if(s2[j]==s1[ps])
					ps++;
			}
			if(ps<n)
				ans += n-ps;
			mn = min(mn, ans);
		}
		fi = mn;
		string s5 = s1; s1 = s2; s2 = s5;
		ll t = n; n = m; m = t;
		ll mn1 = LLONG_MAX;
		for(ll i=0;i<n;i++){
			ll ans = i + m;
			ll ps = i;
			for(ll j=0;j<m;j++){
				if(s2[j]==s1[ps])
					ps++;
			}
			if(ps<n)
				ans += n-ps;
			mn1 = min(mn1, ans);
		}
		fi = min(mn1, fi);

		cout << fi << "\n";
	}

	end_clock();							//This too.
	return 0;
}