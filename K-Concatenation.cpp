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

ll maxSubArraySum(ll *a, ll size)
{
    ll max_so_far = LLONG_MIN, max_ending_here = 0;
 
    for (ll i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
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
		ll n, k, i;
		read(n, k);
		ll a[n];
		F0(i, n) read(a[i]);
		ll pre[n], suf[n];
		pre[0] = a[0];
		for(i=1;i<n;i++)
			pre[i] = pre[i-1] + a[i];
		ll premax = LLONG_MIN;
		F0(i, n) premax = pre[i] > premax ? pre[i] : premax;
		//F0(i, n) cout << pre[i] << " ";
		//cout << "\n";

		ll suff[n];
		suff[n-1] = a[n-1];
		for(i=n-2;i>=0;i--)
			suff[i] = suff[i+1] + a[i];
		ll suffmax = LLONG_MIN;
		F0(i, n) suffmax = suff[i] > premax ? suff[i] : premax;
		//F0(i, n) cout << suff[i] << " ";
		//cout << "\n";
		//cout << premax << "\n" << suffmax << "\n";

		ll sum=0;
		F0(i, n) sum+=a[i];

		ll maximum = maxSubArraySum(a, n);
		if(k>1)
			cout << max(suffmax, max(premax, max((k-1)*sum+suffmax, max((k-1)*sum+premax, max(k*sum, max(maximum, max(premax+suffmax, premax+((k-2)*sum)+suffmax))))))) << "\n";
		if(k==1)
			cout << maximum << "\n";
	}

	end_clock();							//This too.
	return 0;
}