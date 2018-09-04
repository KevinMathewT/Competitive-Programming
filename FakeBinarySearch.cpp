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
	ll n, q; read(n, q);
	ll a[n], b[n]; for(ll i=0;i<n;i++) read(a[i]);

	map<ll, ll> m;
	for(ll i=0;i<n;i++){
		m[a[i]] = i+1;
		b[i] = a[i];
	}
	
	sort(b, b+n);

	while(q--){
		ll x; read(x);
		ll pos = m[x];
		cout << pos << "--\n";

		ll l = 0, h = n-1;
		while(l < h){
			ll mid = (l + h) / 2;
			// cout << "mid - " << mid << "\n";
			if(x == b[mid]){
				l = mid;
				break;
			}
			if(x < b[mid])
				h = mid - 1;
			else
				l = mid + 1;
		}

		ll nofbs = n - l - 1;
		ll nofss = l;

		l = 1, h = n;
		ll cb = 0, cs = 0, c=0, cbb = 0, css = 0;
		while(l < h){
			// cout << "HAha\n";
			ll mid = (l + h) / 2;

			// cout << "pos - " << pos << " " << mid << "\n";
			if(pos == mid)
				break;
			if(pos > mid){
				// cout << a[mid-1] << "\n";
				if(a[mid-1] > x){
					cs++; c++; css++;
				}
				if(a[mid-1] < x)
					cb++;
				l = mid + 1;
			}
			if(pos < mid){
				// cout << "dlkfl " << a[mid-1] << "\n";
				if(a[mid-1] < x){
					cb++; c++; cbb++;
				}
				if(a[mid-1] > x)
					cs++;
				h = mid - 1;
			}
		}

		cout << nofss << " --- " << nofbs << "\n";
		cout << cs << " - " << cb << "\n";

		if(cs > nofbs || cb > nofss){
			cout << -1 << "\n";
			continue;
		}
		cout << max(cbb, css) << "\n";
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

	ll T; read(T);
	while(T--) te();

	end_clock();							//This too.
	return 0;
}