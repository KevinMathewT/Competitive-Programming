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

	ll t;
	read(t);
	while(t--){
		ll n, c, i;
		read(n, c);
		ll a[n];
		F0(i, n) read(a[i]);
		ll low = 1000000000;
		F0(i, n-1)
			low = low < a[i+1]-a[i] ? low : (a[i+1]-a[i]);
		ll high = a[n-1] - a[0];
		while(low<=high){
			ll mid = low+((high-low)/2), mini = 1000000000;
			ll count = 0, ref = a[0];
			F0(i, n-1){
				ll diff = a[i]-ref;
				if(diff>mid){
					count++;
					ref = i;
					mini = mini < diff ? mini : diff;
					continue;
				}
			}
			if(count == c){
				cout << mini;
				break;
			}
			else if(count > c)
				low = mid+1;
			else
				high = mid;
		}
	}

	end_clock();							//This too.
	return 0;
}