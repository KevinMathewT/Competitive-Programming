#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

int main(){
	ll a[5];
	for(ll i=0;i<5;i++) cin >> a[i];
	ll mx = LLONG_MIN, mn = LLONG_MAX;
	ll tot = accumulate(a, a + 5, 0LL);
	for(ll i=0;i<5;i++) mx = max(mx, tot - a[i]), mn = max(mn, tot - a[i]);
	cout << mx << ' ' << mx << "\n";
	return 0;
}