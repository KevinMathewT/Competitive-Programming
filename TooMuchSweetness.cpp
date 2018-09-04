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


ll dp[110][2][500];

bool IsOdd(ll n){ return n % 2 == 1; }

ll dynamicp(ll w, ll t, ll on, ll tw, ll n, ll *arr){
	cout << w << " " << t << " " << on << " " << tw << " " << n << "\n";
	if(t > w)
		return 0;
	if(t == w)
		return 1;
	//if(dp[t][n][n == 1 ? on : tw] != -1)
	//	return dp[t][n][n == 1 ? on : tw];

	ll p = n == 1 ? arr[0] : arr[1];
	ll b = (n == 1 ? arr[3] - on : arr[4] - tw);
	ll s = n == 1 ? arr[5] : arr[6];
	
	if(n == 1) on++;
	else tw++;
	
	ll sum = 0;
	for(ll i=(w-t)/b;i<=s;i++)
		sum += dynamicp(w, t+=i, on, tw, n == 1 ? 2 : 1, arr);

	return sum;
	//return dp[t][n][n == 1 ? on : tw] = sum;
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
		ll p, q, n, b1, b2, s1, s2;
		read(p, q, n);
		read(b1, b2);
		read(s1, s2);
		ll arr[6];
		arr[0]=p;
		arr[1]=q;
		arr[2]=n;
		arr[3]=b1;
		arr[4]=b2;
		arr[5]=s1;
		arr[6]=s2;
		memset(dp, -1, sizeof(dp[0][0][0]) * 110 * 2 * 500);

		cout << dynamicp(n, 0, 0, 0, 1, arr) << "\n\n";
	}

	end_clock();							//This too.
	return 0;
}