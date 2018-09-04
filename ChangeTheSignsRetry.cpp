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
ll a[100100], b[100100];

ll isSmall(ll i){
	if((i == 0 && a[i] < a[i+1]) || (i == n-1 && a[i] < a[i-1]))
		return 1;
	if(i != 0 && i != n-1)
		if(a[i] < a[i-1] && a[i] < a[i+1])
			return 1;

	return 0;
}

ll dp[100100];

vector<ll> DP(ll i, vector<ll> v, vector<ll> c, vector<ll> b, ll size){
	if(i == 1){
		if(a[v[i]] > a[v[i-1]]){
			b.push_back(v[i]);
			dp[1] = a[v[i]];
			if(i != size-1)
				return DP(i+1, v, c, b, size);
			else
				return b;
		}
		else{
			b.push_back(v[i-1]);
			dp[1] = dp[0];
			if(i != size-1)
				return DP(i+1, v, c, b, size);
			else
				return b;
		}
	}
	if(i == size){
		return b;
	}
	if(dp[i-1] >= a[v[i]] + dp[i-2]){
		dp[i] = dp[i-1];
		return DP(i+1, v, b, b, size);
	}
	else{
		c.push_back(v[i]);
		dp[i] = a[v[i]] + dp[i-2];
		return DP(i+1, v, b, c, size);
	}
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
	while(T--){
		read(n);
		for(ll i=0;i<n;i++){
			read(a[i]);
			b[i] = a[i];
		}
	
		for(ll i=0;i<n;i++){
			if(isSmall(i) == 0)
				continue;
			vector<ll> v;
			v.push_back(i);
			ll j;
			for(j=i+2;j<n;j+=2){
				if(isSmall(j) && (a[j-2]+a[j] >= a[j-1])){
					v.push_back(j);
				}
				else
					break;
			}
	
			if(v.size() == 1){
				b[i] = -b[i];
				continue;
			}
	
			dp[0] = a[v[0]];
			vector<ll> x, y, z;
			x.push_back(v[0]);
	
			z = DP(1, v, x, y, v.size());

			for(ll q=0;q<z.size();q++)
				b[z[q]] = -b[z[q]];
	
			i = j - 1;
		}
		for(ll i=0;i<n;i++)
			cout << b[i] << " ";
		cout << "\n";
	}

	end_clock();							//This too.
	return 0;
}