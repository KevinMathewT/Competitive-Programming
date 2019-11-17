#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, m, a[200010], u, v;

ll fun(ll s, ll e, ll k){
	if(s > e)
		return 0;
	u = s;
	v = e;

	ll sum = 0;
	for(ll i=s;i<=e;i++)
		sum += a[i];

	if(k >= (e - s + 1))
		return sum;

	u = s;
	v = s + k - 1;

	ll window = 0;
	for(ll i=s;i<s+k;i++)
		window += a[i];
	ll mx = window;
	ll p = s;
	for(ll i=s+k;i<=e;i++){
		window += a[i];
		window -= a[p++];

		if(window >= mx){
			mx = window;
			u = p;
			v = i;
		}
	}

	return mx;
}

void solve(){
	cin >> n >> m;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll sum = 0;
	for(ll i=0;i<n;i++)
		sum += a[i];

	if(2 * m >= n){
		cout << sum << "\n";
		return;
	}

	ll mx1 = fun(0, n - 1, 2 * m);
	ll mx2 = fun(0, n - 1, m);

	ll y = u, z = v + 1;

	while(z < n)
		a[y++] = a[z++];

	// cout << y << ' ' << z << "\n";
	ll mx3 = fun(0, y-1, m);
	// ll mx4 = fun(z+1, n-1, m);

	// cout << mx1 << ' ' << mx2 << " " << mx3 << " " << mx4 << "\n";

	mx2 = mx2 + mx3;

	cout << max(mx1, mx2) << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}