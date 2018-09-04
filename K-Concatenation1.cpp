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

void calcPrefix(ll *a, ll *pre, ll n){
	pre[0]=a[0];
	for(ll i=1;i<n;i++)
		pre[i]=pre[i-1]+a[i];
}

void calcSuffix(ll *a, ll *suff, ll n){
	suff[n-1]=a[n-1];
	for(ll i=n-2;i>=0;i--)
		suff[i]=suff[i+1]+a[i];
}

ll calcMax(ll *a, ll n){
	ll max = LLONG_MIN, i;
	F0(i, n) max = max > a[i] ? max : a[i];
	return max;
}

ll calcSum(ll *a, ll n){
	ll i, sum=0;
	F0(i, n) sum+=a[i];
	return sum;
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
		ll a[n], pre[n], suff[n];
		F0(i, n) read(a[i]);
		
		calcPrefix(a, pre, n);
		calcSuffix(a, suff, n);
		
		ll premax = calcMax(pre, n);
		ll suffmax = calcMax(suff, n);
		ll maximum = maxSubArraySum(a, n);
		ll sum = calcSum(a, n);

		ll p1 = k*sum;
		ll p2 = suffmax + (k-1)*sum;
		ll p3 = (k-1)*sum + premax;
		ll p4 = maximum;
		ll p5 = suffmax + (k-2)*sum + premax;
		ll p6 = suffmax + premax;

		if(k > 1)
			cout << max(p1, max(p2, max(p3, max(p4, max(p5, p6))))) << "\n";
		else
			cout << maximum << "\n";
	}

	end_clock();							//This too.
	return 0;
}