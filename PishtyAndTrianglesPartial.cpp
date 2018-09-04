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
#define SZ(x) ((ll)x.size())

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

ll getMax(ll arr[], ll n)
{
    ll mx = arr[0];
    for (ll i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
void countSort(ll arr[], ll n, ll exp)
{
    ll output[n];
    ll i, count[10] = {0};
 
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(ll arr[], ll n)
{
    ll m = getMax(arr, n);
 
    for (ll exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll n, q;
	read(n, q);
	ll a[n];
	ll t[n];
	for(ll i=0;i<n;i++)
		read(a[i]);

	while(q--){
		ll ch, x, y, flag = 1;
		read(ch, x, y);
		if(ch == 1){
			a[x-1] = y;
			continue;
		}
		ll c = 0;
		for(ll i=x-1;i<=y-1;i++)
			t[c++] = a[i];
		radixsort(t, y-x+1);
		for(ll i=(y-x);i>=2;i--){
			if((t[i-2] > (t[i] - t[i-1])) && (t[i-2] < (t[i] + t[i-1]))){
				cout << t[i] + t[i-1] + t[i-2] << "\n";
				flag = 0;
				break;
			}
		}
		if(flag == 1)
			cout << 0 << "\n";
	}
	

	end_clock();							//This too.
	return 0;
}