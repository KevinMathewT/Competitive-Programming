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
		ll n, i;
		read(n);
		ll a[n];
		F0(i, n) read(a[i]);
		ll cum1[n];
		ll cum2[n];
		cum1[0] = a[0];
		cum2[0] = -1*a[0];
		for(ll i=1;i<n;i++)
			if(i%2 == 0)
				cum1[i]=cum1[i-1]+a[i];
			else
				cum1[i]=cum1[i-1]-a[i];
		//for(ll i=1;i<n;i++)
		//	cum1[i]+=cum1[i-1];
		for(ll i=1;i<n;i++)
			if(i%2 != 0)
				cum2[i]=cum2[i-1]+a[i];
			else
				cum2[i]=cum2[i-1]-a[i];
		//for(ll i=1;i<n;i++)
		//	cum2[i]+=cum2[i-1];

		ll q;
		read(q);
		while(q--){
			ll l, r;
			read(l, r);
			if(l%2 == 0)
				if(l == 1)
					cout << cum2[r-1] << "\n";
				else
					cout << cum2[r-1]-cum2[l-2]<<"\n";
			else
				if(l == 1)
					cout << cum1[r-1] << "\n";
				else
					cout << cum1[r-1]-cum1[l-2]<<"\n";
		}
	}

	end_clock();							//This too.
	return 0;
}