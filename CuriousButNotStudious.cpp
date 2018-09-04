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
	cout.tie(0);							//or this.

	ll t;
	read(t);
	while(t--){
		ll n;
		read(n);
		ll a[n], b[n];
		F0(i, n) read(a[i]);
		F0(i, n) read(b[i]);
		ll d[n];
		F0(i, n) d[i] = abs(a[i] - b[i]);
		ll s1=0;
		F0(i, n) s1+=d[i];
		sort(d, d+n);
		if(s1%2 != 0){
			cout << "NO\n";
			continue;
		}
		ll k=s1/2;
		ll s2=0;
		s1 = 0;
		for(ll i=n-1;i>=0;i--)
			if(s1+d[i]<=k)
				s1 += d[i];
			else s2 += d[i];
		if(s1 == s2)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	end_clock();							//This too.
	return 0;
}