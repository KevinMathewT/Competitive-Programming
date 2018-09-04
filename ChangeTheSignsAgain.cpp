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

ll n;
ll a[100100];
ll b[100100];

bool isSmall(ll p){
	if(p == 0 && a[p] < a[p+1])
		return true;
	else if(p == n-1 && a[p] < a[p-1])
		return true;
	else if(p != 0 && p != (n-1) && a[p] < a[p+1] && a[p] < a[p-1])
		return true;
	return false;
}

void te(){
	read(n);
	for(ll i=0;i<n;i++){ read(a[i]); b[i] = a[i]; }

	for(ll i=0;i<n;i++) cout << i << " " << isSmall(i) << "----\n" ;

	for(ll i=0;i<n;i++){
		vector<ll> v;
		bool w = false;
		w = isSmall(i);
		ll ashfgsgfhj;

		if(w) cout << i << "-\n";

		if(w){
			for(ashfgsgfhj=i+2;ashfgsgfhj<n;ashfgsgfhj+=2){
				if(isSmall(ashfgsgfhj))
					v.push_back(ashfgsgfhj);
				else
					break;
			}
		}

		if(w) cout << ashfgsgfhj << "-\n";

		if(w && v.size() == 0){
			b[i] = -a[i];
			continue;
		}

		if(w && v.size() > 0){
			cout << w << "--\n";
			ll s1 = 0, s2 = 0;
			for(ll j=0;j<v.size();j+=2)
				s1 += a[v[i]];
			for(ll j=1;j<v.size();j+=2)
				s2 += a[v[i]];

			if(s1 >= s2){
				for(ll j=0;j<v.size();j+=2)
					b[v[i]] = -a[v[i]];
			}
			else
				for(ll j=1;j<v.size();j+=2)
					b[v[i]] = -a[v[i]];

		}
		i = ashfgsgfhj;
	}

	for(ll i=0;i<n;i++)
		cout << b[i] << " ";
	cout << "\n";
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