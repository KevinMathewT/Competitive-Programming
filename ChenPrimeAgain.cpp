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

	
    bool a[100+1];
    memset(a, true, sizeof(a));
 
    for (ll i=2; i*i<=100; i++)
    {
        if (a[i] == true)
        {
            for (ll j=i*2; j<=100; j += i)
                a[j] = false;
        }
    }

    ll b[100], c=0;
    for(ll i=0;i<sizeof(a);i++)
    	if(a[i] == true)
    		b[c++]=i;

    for(ll i=0;i<c;i++)
    	for(ll j=i;j>=0;j--)
    		a[b[i]*b[j]]=true;

    F0(i, 100) cout << i << " - "<< b[i] << "\n";
    F0(i, 100) cout << i << " - "<< a[i] << "\n";

    ll cum[sizeof(a)];
    cum[0]=a[0];
    for(ll i=1;i<=sizeof(a);i++)
    	if(a[i])
    		cum[i]=cum[i-1]+1;
    	else
    		cum[i]=cum[i-1];

    ll t;
    read(t);
    while(t--){
    	ll l, r;
    	read(l, r);
    	cout<<cum[r+2]-cum[l+1]<<"\n";
    }


	end_clock();							//This too.
	return 0;
}