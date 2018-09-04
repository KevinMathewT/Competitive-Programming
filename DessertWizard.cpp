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

void te(){
	ll n; read(n);
	ll a[n]; for(ll i=0;i<n;i++) read(a[i]);
	ll dp[n]; dp[0] = a[0]; for(ll i=1;i<n;i++) dp[i] = dp[i-1] + a[i];
	ll ans_max = LLONG_MIN;

	ll dp_forward_max[n];
	dp_forward_max[0] = a[0];
	ll dp_reverse_max[n];
	dp_reverse_max[n-1] = a[n-1];
	ll dp_forward_min[n];
	dp_forward_min[0] = a[0];
	ll dp_reverse_min[n];
	dp_reverse_min[n-1] = a[n-1];
	ll forward_curr_max = a[0];
	ll reverse_curr_max = a[n-1];
	ll forward_curr_min = a[0];
	ll reverse_curr_min = a[n-1];	

	for(ll i=1;i<n;i++){
		forward_curr_max = max(forward_curr_max, forward_curr_max + a[i]);
		reverse_curr_max = max(reverse_curr_max, reverse_curr_max + a[n-i-1]);
		forward_curr_min = min(forward_curr_min, forward_curr_min + a[i]);
		reverse_curr_min = min(reverse_curr_min, reverse_curr_min + a[n-i-1]);
		dp_forward_max[i] = max(forward_curr_max, dp_forward_max[i-1]);
		dp_reverse_max[n-i-1] = max(reverse_curr_max, dp_reverse_max[n-i]);
		dp_forward_min[i] = min(forward_curr_min, dp_forward_min[i-1]);
		dp_reverse_min[n-i-1] = min(reverse_curr_min, dp_reverse_min[n-i]);
	}

	// for(ll i=0;i<n;i++){
	// 	cout << dp_forward_max[i] << " " << dp_forward_min[i] << " " << dp_reverse_max[i] << " " << dp_reverse_min[i] << "\n";
	// }

	for(ll i=1;i<n-1;i++){
		ans_max = max(ans_max, max(abs(dp_forward_max[i]-dp_reverse_min[i+1]), abs(dp_reverse_max[i]-dp_forward_min[i-1])));
	}

	if(ans_max == LLONG_MIN)
		cout << abs(a[1]-a[0]) << "\n";
	else
		cout << ans_max << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T; read(T);
	while(T--) te();

	end_clock();							//This too.
	return 0;
}