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
	//start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll n, i;
	read(n);
	ll h[n], s=n;
	F0(i, n) read(h[i]);
	ll q;
	read(q);
	while(q--){
		ll x, y;
		read(x, y);
		ll c=0, p=0, a[30];
		while((1<<c) <= x){
			if((1<<c) & x){
				a[p]=1<<c; p+=1;
			}
			c++;
		}
		//cout<<c<<" "<<p<<"\n";
		for(ll j=0;j<(1<<p);j++){
			ll sum=0;
			for(ll k=0;k<p;k++)
				if(j&(1<<k))
					sum+=a[k];
			if(h[sum]<=0) continue;
			h[sum]-=y;
			if(h[sum]<=0)
				s--;
		}
		cout << s << "\n";
	}

	//end_clock();							//This too.
	return 0;
}