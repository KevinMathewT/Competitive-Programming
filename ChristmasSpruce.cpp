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

	ll n, i, j;
	read(n);
	vector< vector<ll> > v(n+1, vector<ll>());
	for(i=2;i<=n;i++){
		ll u;
		read(u);
		v[u].push_back(i);
	}
	F1(i, n){
		F0(j, v[i].size())
			cout << v[i][j] << " ";
		cout << "\n";
	}

	ll flag=0;
	F1(i, n){
		ll c=0;
		F0(j, v[i].size())
			if(v[j].size() == 0)
				c++;
		cout << c << "\n";
		if(c!=0 || c!=3){
			flag = 1;
			break;
		}
	}
	if(flag == 1) cout << "NO" << "\n";
	else cout << "YES" << "\n";

	end_clock();							//This too.
	return 0;
}