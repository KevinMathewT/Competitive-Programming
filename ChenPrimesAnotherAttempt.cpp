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

	ll a[10009], i;
	F0(i, 10009) a[i]=1;
	a[0]=0;
	a[1]=0;
	for(i=2;i*i<10009;i++){
		if(a[i] == 1){
			for(ll j=2*i;j<10009;j+=i)
				a[j]=0;
		}
	}
	vl primes;
	for(i=0;i<10009;i++)
		if(a[i] == 1)
		primes.push_back(i);

	ll b[10009];
	for(i=0;i<primes.size();i++){
		for(ll j=i;j>=0;j--)
			if(primes[i]*primes[j] < 10009)
				b[primes[i]*primes[j]]=1;
			else
				break;
	}

	ll cum[10009];
	cum[0]=a[0];
	for(i=1;i<10007;i++)
		if(a[i] == 1 && a[i+2] == 1 || a[i] == 1 && b[i+2] == 1)
			cum[i] = cum[i-1]+1;
		else
			cum[i]=cum[i-1];

	ll t;
	read(t);
	while(t--){
		ll l, r;
		read(l, r);
		for(ll i=l;i<=r+4;i++)
			cout << i << " - " <<a[i] <<" - "<<cum[i]<< "\n";
		cout << "\n";
		cout << cum[r]-cum[l-1] <<"\n";
	}


	end_clock();							//This too.
	return 0;
}