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

	ll s1[10000+5], s2[10000+5];
	for(ll i=0;i<10000+5;i++){
		s1[i] = 1; s2[i] = 1;
	}
	
	vector<ll> v;	
	for(ll i=2;i<10000+5;i++){
		if(s1[i]==1){
			v.push_back(i);
			for(ll j=i*2;j<10000+5;j+=i){
				s1[j]=0; s2[j]=0;
			}
		}
	}

	for(ll i=0;i<v.size();i++)
		for(ll j=0;j<=i;j++)
			if(v[i]*v[j] < 10000+5 && v[i]*v[j] > 0)
				s2[v[i]*v[j]] = 1;

	ll cum[10000+5];
	for(ll i=1;i<10000+3;i++)
		if(s1[i]==1 && s2[i+2]==1)
			cum[i]=cum[i-1]+1;
		else
			cum[i]=cum[i-1];

	ll t;
	read(t);
	while(t--){
		ll l, r;
		read(l, r);
		if(l == 0)
			cout << cum[r] << "\n";
		else
			cout << cum[r]-cum[l-1] << "\n";
	}


	end_clock();							//This too.
	return 0;
}